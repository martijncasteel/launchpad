/**
 * launchpad - usb hid device
 * 
 * @author Martijn Casteel
 * @date 2022-12-22
*/

#define __ATmega32U4__
#define F_CPU 16000000UL

#include "usb.h"

#include <avr/io.h>
#include <util/delay.h>

uint8_t data = 0;
 
int main()
{
  DDRF |= (1 << DDF0);        // Make pin 23 be an output.

#ifdef DEBUG
  // TODO build serial output uart.h?
  // https://www.baldengineer.com/alternatives-to-arduinos-serial-monitor.html
  Serial.begin(9600); // use $ screen /dev/ttyUSB0 9600 
  Serial.println("Starting!");
#endif

  init();                     // initialize usb connection


  while(1);
  // {
  //   PORTF |= (1 << PORTF0);   // Turn the LED on.
  //   _delay_ms(50);
  //   PORTF &= ~(1 << PORTF0);  // Turn the LED off.
  //   _delay_ms(50);
  //   PORTF |= (1 << PORTF0);   // Turn the LED on.
  //   _delay_ms(50);
  //   PORTF &= ~(1 << PORTF0);  // Turn the LED off.
  //   _delay_ms(50);
  //   PORTF |= (1 << PORTF0);   // Turn the LED on.
  //   _delay_ms(200);
  //   PORTF &= ~(1 << PORTF0);  // Turn the LED off.
  //   _delay_ms(50);
  // }

  return 0;
}