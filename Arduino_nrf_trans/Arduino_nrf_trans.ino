//for transmitter
#define LEFTa 13
#define LEFTb 12
#define RIGHTa 10
#define RIGHTb 11
#define ENABLE1 6
#define ENABLE2 9
#define CE 7
#define CSN 8
#include <SPI.h>
#include <RF24.h>

char x;
 byte add = 0;
RF24 myRadio(CE,CSN);
void forward()
{
   analogWrite(ENABLE1,128);
  analogWrite(ENABLE2,128);
    digitalWrite(LEFTa,HIGH);
    digitalWrite(LEFTb,LOW);
    digitalWrite(RIGHTa,HIGH);
    digitalWrite(RIGHTb,LOW);
    
}
void backward()//need to change the direction of rotation
{
  analogWrite(ENABLE1,128);
  analogWrite(ENABLE2,128);  
    digitalWrite(LEFTb,HIGH);
    digitalWrite(LEFTa,LOW);
    digitalWrite(RIGHTb,HIGH);
    digitalWrite(RIGHTa,LOW);
  
}
void rightTurn()
{
  analogWrite(ENABLE1,128);
  analogWrite(ENABLE2,128);
     digitalWrite(LEFTa,HIGH);
    digitalWrite(LEFTb,LOW);
    digitalWrite(RIGHTb,HIGH);
    digitalWrite(RIGHTa,LOW);
  
}
void leftTurn()
{
   analogWrite(ENABLE1,128);
  analogWrite(ENABLE2,128);
  
   digitalWrite(LEFTb,HIGH);
    digitalWrite(LEFTa,LOW);
   digitalWrite(RIGHTa,HIGH);
    digitalWrite(RIGHTb,LOW);
   
}

void Stop()
{
 
    digitalWrite(LEFTa,LOW);
    digitalWrite(LEFTb,LOW);
    digitalWrite(RIGHTb,LOW);
    digitalWrite(RIGHTa,LOW);
    
}

  void setup() {
    Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(LEFTa,OUTPUT);
pinMode(LEFTb,OUTPUT);
pinMode(RIGHTa,OUTPUT);
pinMode(RIGHTb,OUTPUT);
pinMode(ENABLE1,OUTPUT);
pinMode(ENABLE2,OUTPUT);
//nrf code for transmitter

RF24 myRadio(CE,CSN);
 byte add = 0;
myRadio.begin();
myRadio.setChannel(10);
myRadio.setPALevel(RF24_PA_MAX);
myRadio.setDataRate(RF24_1MBPS);
myRadio.openWritingPipe(add);
 
}

void loop() {
 
    if(Serial.available()>0) 
    { 
      x=Serial.read();
       myRadio.write(&x,sizeof(x));
    }
       
 
}
