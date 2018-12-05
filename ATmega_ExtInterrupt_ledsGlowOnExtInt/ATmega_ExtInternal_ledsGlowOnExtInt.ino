#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
ISR(INT0_vect)
{
 PORTB|=(1<<PB0)|(1<<PB1)|(1<<PB2);
  _delay_ms(1000);
}
int main (void)
{
 sei();
 DDRB |=(1<<PB0)|(1<<PB1)|(1<<PB2); 
EIMSK|=(1<<INT0);
 EICRA |=(0<<ISC01)|(1<<ISC00);
  while(1){
  PORTB =(1<<PB0);
    _delay_ms(1000);
   
    PORTB =(1<<PB1);
      _delay_ms(1000);
   
     PORTB =(1<<PB2);
      _delay_ms(1000);
   
  }
  
}
