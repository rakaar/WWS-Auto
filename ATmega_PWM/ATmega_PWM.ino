#include <avr/io.h>
#define F_CPU 16000000UL
int main (void)
{
   TCCR0B|=(1<<CS02);//prescaling factor- 256
   TCNT0=0;//initializing the timer
   DDRD |=(1<<PD5)|(1<<PD6);//output on both pd pins
 
 TCCR0A|=(1<<COM0A1)|(0<<COM0A0)|(1<<WGM01)|(1<<WGM00);//wgm indicates fast pwm. comoa indicates non-inverting output
  TCCR0A|=(1<<COM0B1)|(0<<COM0B0)|(1<<WGM01)|(1<<WGM00);
  OCR0A=20;//compare value
  OCR0B=255;
  
  while (1){};//mandatory infinite loop


}
