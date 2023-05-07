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
int8_t check_buttons(uint8_t* dout) {
  
  // bitwise not the register, pull-up resistors are used for the buttons
  uint8_t current = ~PIND;
  uint8_t data = current & 0b11111100;  // don't take first two bits for BTN6

  // BTN6 check if state has changed, xor PIND1
  if ((current & (1 << PIND1)) ^ (state & (1 << PIND1))) {

    if (current & (1 << PIND1)) {       // button is pressed    
      data |= 0b00000011;               // pressed, unmute
    } else {
      data |= 0b00000001;               // released, mute on 
    }
  }

  *dout = data;                         // fill the register
  state = current;                      // remember state for next iteration
  return 0;
}


/**
 * Animates the LED in such a way it is able to display several modes. Modes
 * including caller waiting, active caller, etc.
 * 
 * @param din byte holding several states defined in usb.h 
 */
int8_t animate_led(uint8_t* din){

  if (*din > 0)
    PORTF |= (1 << LED);
  else
    PORTF &= ~(1 << LED);

  return 0;
}