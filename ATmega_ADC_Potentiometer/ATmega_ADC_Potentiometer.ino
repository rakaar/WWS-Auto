#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
int main (void)
{
  float x;
 DDRC=0b000000;//potentimeter connection input
DDRD=0b11111111;//led bulbs connection output
   ADMUX |= (0<<REFS0)|(0<<REFS1)|(1<<ADLAR)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(0<<MUX0);
   ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(0<<ADPS0);
  Serial.begin(9600);//Communication btn lap and arduino
  while(1){
      ADCSRA |= (1<<ADSC);
    
    while(ADCSRA&(1<<ADSC));
     x=(float)ADC ;//x=(ADC*5)/65536.0
       x=(x*5)/65536.0;
    
      
    Serial.println(x);
      
     
    //conditions for bulbs to glow
    if((x>0)&&(x<1)) PORTD=0b00010000;
    else if((x>1)&&(x<2)) PORTD=0b00001000;
    else if((x>2)&&(x<3)) PORTD=0b00000100;
    else if((x>3)&&(x<4)) PORTD=0b00010010;
    else if((x>4)&&(x<5)) PORTD=0b00010001;
  
    
  
  
  }



}
