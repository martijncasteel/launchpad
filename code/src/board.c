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
#include <util/delay.h>

uint8_t state = 0x00;

int8_t check_buttons(uint8_t* data) {
  
  state = PIND;//PORTD;

  // xor state and port, & with port -> changed buttons which are active

  *data = ~state;

  if (*data > 0)
    PORTF |= (1 << PF0);
  else 
    PORTF &= ~(1 << PF0);

  _delay_ms(50);
  return 0;
}