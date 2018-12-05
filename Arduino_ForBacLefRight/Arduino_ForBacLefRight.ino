#define LEFTa 13
#define LEFTb 12
#define RIGHTa 10
#define RIGHTb 11
#define ENABLE1 6
#define ENABLE2 9
char x;

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
}

void loop() {
 
    if(Serial.available()>0) 
    { 
      x=Serial.read();
    
     if(x=='F') { forward();}
     else if(x=='B') { backward();}
     else if(x=='L') { leftTurn();}
     else if(x=='R'){ rightTurn();}
     else if(x=='S') { Stop();}
      }
}
