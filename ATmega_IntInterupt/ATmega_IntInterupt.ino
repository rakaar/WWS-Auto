#define F_CPU 16000000UL
#include <avr/io.h>. 
#include <avr/interrupt.h>
Volatile unsigned int a;//its value keeps on changing
ISR (TIMER0_0VF_vect)
{ a++;}
Int main ()

{
sei();
TIMSK0|=(1<<TOEIO);//CALLING THE TIMER INTERRUPT
TCCR0B|=(1<CS01)//prescaling factor from data sheet
TCNT0=0;//INTIALISE THE TIMER;
Serial.begin(9600)//eshtablish connection between lap and arduino
while(1) { Serial.println(a);}//prints the value till 65336
}
