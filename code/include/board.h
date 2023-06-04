/**
 * @file board.h
 * @brief Header file contains the layout of the board
 * 
 * @author Martijn Casteel
 * @date 2022-12-22
*/

#include <avr/io.h>

#ifndef BOARD_H
#define BOARD_H

/**
 * Layout of the board, all buttons are connected to the D 
 * register (PORTD). Should have made this mapping way 
 * simpler, revision 2 perhaps?
 * 
 * There is a single led on PORTF0.
 * 
 *  +------+------+------+------+
 *  | BTN0 | BTN2 | BTN4 |      |
 *  +------+------+------+ BTN6 |
 *  | BTN1 | BTN3 | BTN5 |      |
 *  +------+------+------+------+
 * 
 */

#define BTN0 PIND6
#define BTN1 PIND7
#define BTN2 PIND5
#define BTN3 PIND4
#define BTN4 PIND2
#define BTN5 PIND3
#define BTN6 PIND1

/**
 * BTN0  - flash
 * BTN1  - camera toggle
 * BTN2  - volume increment
 * BTN3  - volume decrement
 * BTN4  - volume mute
 * BTN5  - microphone mute toggle
 * BTN6  - Hold to unmute microphone
 * 
 * PIND0 - 
 * PIND1 - hold to unmute microphone
 * PIND2 - volume mute
 * PIND3 - microphone mute toggle 
 * PIND4 - volume decrement
 * PIND5 - volume increment
 * PIND6 - flash
 * PIND7 - camera toggle 
 */

#define LED PORTF0

int8_t check_buttons(uint16_t* dout);
int8_t animate_led(uint8_t* din);

#endif