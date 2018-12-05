#define F_CPU 16000000UL
#include<avr/io.h>
#include<avr/interrupt.h>
volatile unsigned int a;
ISR(TIMER0_OVF_vect)
{ 
  a++;
  Serial.println(a);
}
int main()
{
  sei();
  Serial.begin(9600);
  TIMSK0|=(1<<TOIE0);
  TCCR0B|=(1<<CS02)&~(1<<CS00)&~(1<<CS01);
  TCNT0=0;
  while(1) { }//COMMMON MISTAKES-Dont keep the tcnt0=0 in the while loop-it means u are repeatedly initializing the timer.
  //other common mistake-not keeping the while loop at all will exit the main function after one overflow.
  
  
  
  return 0;
}
