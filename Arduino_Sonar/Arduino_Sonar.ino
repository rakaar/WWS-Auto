#define trig 9
#define echo 10

long time;
int dist;


void setup() {
  // put your setup code here, to run once:
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
 delayMicroseconds(2);

digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

time= pulseIn(echo,HIGH);
dist = (0.034 *time)/2;

Serial.println(dist);
}
