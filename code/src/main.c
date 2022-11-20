#define __ATmega32U4__
#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
 
int main()
{
  DDRF |= (1 << DDF0);        // Make pin 23 be an output.  
  while(1)
  {
    PORTF |= (1 << PORTF0);   // Turn the LED on.
    _delay_ms(50);
    PORTF &= ~(1 << PORTF0);  // Turn the LED off.
    _delay_ms(50);
    PORTF |= (1 << PORTF0);   // Turn the LED on.
    _delay_ms(50);
    PORTF &= ~(1 << PORTF0);  // Turn the LED off.
    _delay_ms(50);
    PORTF |= (1 << PORTF0);   // Turn the LED on.
    _delay_ms(200);
    PORTF &= ~(1 << PORTF0);  // Turn the LED off.
    _delay_ms(50);
  }

  return 0;
}