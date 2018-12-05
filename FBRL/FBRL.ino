#define LEFTa 2
#define LEFTb 3
#define RIGHTa 4
#define RIGHTb 5

void forward()
{
  while(1){ 
    digitalWrite(LEFTa,HIGH);
    digitalWrite(LEFTb,LOW);
    digitalWrite(RIGHTa,HIGH);
    digitalWrite(RIGHTb,LOW);
    }
}
void backward()//need to change the direction of rotation
{
  while(1){ 
    digitalWrite(LEFTb,HIGH);
    digitalWrite(LEFTa,LOW);
    digitalWrite(RIGHTb,HIGH);
    digitalWrite(RIGHTa,LOW);
    }
}
void rightTurn()
{
  while(1){
     digitalWrite(LEFTb,HIGH);
     digitalWrite(LEFTa,LOW);
     digitalWrite(RIGHTa,HIGH);
    digitalWrite(RIGHTb,LOW);
    }
}
void leftTurn()
{
  while(1){ 
    digitalWrite(LEFTa,HIGH);
    digitalWrite(LEFTb,LOW);
    digitalWrite(RIGHTb,HIGH);
    digitalWrite(RIGHTa,LOW);
    }
}
  void setup() {
  // put your setup code here, to run once:
pinMode(LEFTa,OUTPUT);
pinMode(LEFTb,OUTPUT);
pinMode(RIGHTa,OUTPUT);
pinMode(RIGHTb,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


}
