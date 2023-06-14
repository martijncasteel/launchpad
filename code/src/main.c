/**
 * @name launchpad
 * @file main.c
 * 
 * @brief Mini keypad acts a usb hid device to control default functions
 * @link https://github.com/martijncasteel/launchpad
 * 
 * During covid I wanted to mute my mic with a simple key press. Unfortunatly I
 * am not allowed to write own drivers to solve this problem on the computer side.
 * 
 * Next to that I found it very interesting to design and use a custom pcb made 
 * somewhere in china. I learned lots of stuff doing this project such as pcb design,
 * revisited c and started using avr-gcc and avrdude. Ben Eater had some cool videos
 * about the USB protocol and learned lots on USB as well. 
 * 
 * Let's say, plugging in a USB device will never be the same! 
 * 
 * @author Martijn Casteel
 * @date 2022-12-22
 */

#define __ATmega32U4__
#define F_CPU 16000000UL

#include "board.h"
#include "usb.h"

#include <avr/io.h>
#include <util/delay.h>

int main()
{

  PORTD = 0xff;                 // pull up resistors, low is pressed
  DDRD &= 0x00;                 // data direction to read of PORTD
  
  DDRF |= (1 << LED);           // Make pin 23 / PORTF0 be an output

  data_t* data = usb_init();  // initialize usb connection
  uint8_t counter = 0;          // counter to check buttons once every 50 ms

  while(1) {

    if (counter % 50 == 0) {
      check_buttons(&(data->dout));
      counter = 0;
    }

    // control led
    animate_led(&(data->din));
    
    counter++;
    _delay_ms(1); 
  }

  return 0;
}