/**
 * @file board.c
 * @brief Controller for buttons of the launchpad
 * 
 * This contains all logic required for the buttons itself, debounce logic
 * and setting the correct values for the usb report.
 * 
 * @author Martijn Casteel
 * @date 2022-12-27
 */

#include "board.h"
#include <avr/io.h>

uint8_t state = 0x00;

/**
 * Checks the state of the buttons and specifically does some logic for the
 * push-to-talk button. The report descriptor is mapped on the PIND register.
 * So minimal manipulations have to be done. 
 * 
 * Debouncing is not required, buttons trigger on a rising edge (OOC). Volume
 * increment and decrement uses a retrigger mechanism (RTC), these buttons
 * can be hold down. 
 * 
 * The push-to-talk button uses a relative no preffered state on/off control. 
 * It mimics two seperate buttons in two bits. 0b11 is off and 0b01 is on.
 * 
 * @param dout pointer to memory address send as report
 */
int8_t check_buttons(uint16_t* dout) {

  // if both reports are not cleared, wait another cycle
  if ( *dout > 0 ) {
    return 1;
  }

  // bitwise not the register, pull-up resistors are used for the buttons
  uint8_t reading = ~PIND;  

  /**
   * Some logic to only get single shot on press down, using
   * bitwise operator _xor_ and _and_. Also compute if a button
   * is released. Together with a delay in main.c this will also 
   * debounce the button. 
   * 
   *  +---+---------+-------+---------+----------+
   *  | # | reading | state | pressed | released |
   *  +---+---------+-------+---------+----------+
   *  | 1 | true    | false | true    | false    |
   *  | 2 | true    | true  | false   | false    |
   *  | 3 | false   | true  | false   | true     |
   *  +---+---------+-------+---------+----------+
   */
  uint8_t pressed = (reading ^ state) & reading;
  uint8_t released = (reading ^ state) & state;
  state = reading;


  uint16_t data = 0;


  // --- REPORT 1 --- 

  /**
   * Three buttons can control the speaker volume. The increment 
   * and decrement volume buttons are retrigger controls. As long
   * as the button is pressed the volume will change. These 
   * buttons intentionally make use of the raw reading.
   * 
   * The third button is a button to mute and unmute the speaker. 
   */
  if (reading & (1 << BTN2)) {            // volume increment
    data |= (1 << 8);

  } else if (reading & (1 << BTN3)) {     // volume decrement
    data |= (1 << 9);

  } else if (pressed & (1 << BTN4)) {     // volume mute
    data |= (1 << 10);
  }

  /**
   * In a later amendment the camera access toggle was added to
   * the HID usage tables. IT should toggle whether an application
   * has access to the camera. 
   */
  if (pressed & (1 << BTN1)) {            // camera toggle
    data |= (1 << 11);
  } 



  // --- REPORT 2 ---

  /**
   * According to documentation flash created a momentary on hook
   * condition. Hence it should end a call. 
   */
  if (pressed & (1 << BTN0)) {            // flash
    data |= (1 << 3);
  } 
  
  /**
   * The microphone is the main goal of this project. There are
   * two buttons. BTN5 can toggle the microphone mute/unmute. 
   * 
   * The larger button, BTN6, is intended to hold to unmute the
   * microphone, on release the microphone is muted again.
   */
  if(pressed & (1 << BTN6)) {             // unmute on hold
    data |= 0b0011;

  }else if (released & (1 << BTN6)) {     // mute after release
    data |= 0b0001;

  } else if (pressed & (1 << BTN5)) {     // toggle mute
    data |= (1 << 2);
  }


  *dout = data;                           // fill the register
  return 0;
}


/**
 * Animates the LED in such a way it is able to display several modes. Modes
 * including caller waiting, active caller, etc.
 * 
 * @todo implement out reports, pay attention to byte alignment
 * @param din byte holding several states defined in usb.h 
 */
int8_t animate_led(uint8_t* din){

  if (din > 0)
    PORTF |= (1 << LED);
  else
    PORTF &= ~(1 << LED);

  return 0;
}