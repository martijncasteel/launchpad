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

#define LED DDF0

/**
 * Layout of the board, all are connected
 * to the D register (PORTD).
 * 
 *  +------+------+------+------+
 *  | BTN0 | BTN2 | BTN4 |      |
 *  +------+------+------+ BTN6 |
 *  | BTN1 | BTN3 | BTN5 |      |
 *  +------+------+------+------+
 */
#define BTN0 PORTD6
#define BTN1 PORTD7
#define BTN2 PORTD5
#define BTN3 PORTD4
#define BTN4 PORTD2
#define BTN5 PORTD3
#define BTN6 PORTD1

#define DEFAULT = 0x00;

int8_t check_buttons(uint8_t* data);

#endif