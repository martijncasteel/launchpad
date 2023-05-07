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
 * increment and decrement uses a retrigger mechanism (RTC). I looks like the 
 * volume mute button has some debouncing issues. 
 * 
 * The push-to-talk button uses a relative no preffered state on/off control. 
 * It mimics two seperate buttons in two bits. 0b11 is off and 0b01 is on.
 * 
 * @param dout pointer to memory address send as report
 */
int8_t check_buttons(uint32_t* dout) {

  // if register is not cleared, wait another cycle
  if ( *dout > 0 ) {
    return 1;
  }
  
  // bitwise not the register, pull-up resistors are used for the buttons
  uint8_t current = ~PIND;
  uint8_t changes = current ^ state;
  state = current;                      // remember state for next iteration

  uint32_t data = 0;

  uint8_t *modifiers = (uint8_t*) &data;
  uint8_t *key_1 = (uint8_t*)(&data + 1);

  if (changes & (1 << PIND1)) {         // toggle mute when pressed
    // ctrl+space
    *modifiers = LCTRL;
    *key_1 = KEY_SPACE;

  } else if (changes & (1 << PIND2)) {  // toggle video
    // ctrl + shift + O
    *modifiers = LCTRL | LSHIFT;
    *key_1 = KEY_O;

  } else if (changes & (1 << PIND3)) {  // toggle microphone mute
    // ctrl + shift + M
    *modifiers = LCTRL | LSHIFT;
    *key_1 = KEY_M;

  } else if (changes & (1 << PIND4)) {  // volume decrement
    data |= 0x10000000;

  } else if (changes & (1 << PIND5)) {  // volume increment
    data |= 0x01000000;

  } else if (changes & (1 << PIND6)) {  // hang up phone call
    // ctrl + shift + H
    *modifiers = LCTRL | LSHIFT;
    *key_1 = KEY_H;
    
  } else if (changes & (1 << PIND7)) {  // raise/lower hand
    // ctrl + shift + K
    *modifiers = LCTRL | LSHIFT;
    *key_1 = KEY_K;
  } 
  
  *dout = data;                       // fill the register
  return 0;
}


/**
 * Animates the LED in such a way it is able to display several modes. Modes
 * including caller waiting, active caller, etc.
 * 
 * @param din byte holding several states defined in usb.h 
 */
int8_t animate_led(uint8_t* din){
  
  // TODO blink when call is waiting, on when mic on

  if (*din > 0)
    PORTF |= (1 << LED);
  else
    PORTF &= ~(1 << LED);

  return 0;
}
