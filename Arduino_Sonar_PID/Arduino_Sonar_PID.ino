#define trig 9
#define echo 8
#define thr 30

#define el 6 //enable b  
#define er 3 //enable a

#define l1 13
#define l2 12
#define r1 10
#define r2 11
long duration;
int distance;

//analogWrite(el,200*k);
//analogWrite(er,155*k);
unsigned long int currenttime, pasttime=0, t;
int a;
float kp=0.055, ki=0, kd=0;
float error, desired=90, current, values, errorprior, d, i=0;

void setup() {
  // put your setup code here, to run once:

 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 
 pinMode(er,OUTPUT);
 pinMode(el,OUTPUT);
 
 digitalWrite(l1,HIGH);
 digitalWrite(l2,LOW);
 digitalWrite(r1,HIGH);
 digitalWrite(r2,LOW);

    pinMode(trig, OUTPUT); // Sets the trigPin as an Output
    pinMode(echo, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600);
 
 
}

void loop() {
  //Sonar 
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

duration= pulseIn(echo,HIGH);
distance = (0.034 *duration)/2;

Serial.println(distance);
//PID part
   currenttime=millis();
    t=currenttime-pasttime;
    pasttime=currenttime;
    error = thr - distance;
    d= (error - errorprior)/t;//constant for differentiation parrt-Kd
    i = i + (t*error);//constant for integration part-Ki

    values = (kp*error + ki*i + kd*d);//the formula of PID

    if(values>1)values=1;
    else if(values<-1)values=-1;
    Serial.println("values:");
    Serial.println(values);
    if(values<0){
      digitalWrite(l1,HIGH);//move backward since the value or input is low
      digitalWrite(l2,LOW);
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
   analogWrite(el,(int)(-values)*200);//doing the Pulse Width Modulation
   analogWrite(er,(int)(-values)*180);
              }

          if(values>0){
      digitalWrite(l2,HIGH);//move forward since the value or input is high
      digitalWrite(l1,LOW);
      digitalWrite(r2,HIGH);
      digitalWrite(r1,LOW);
   analogWrite(el,(int)values*200);//doing the Pulse Width Modulation
   analogWrite(er,(int)values*180);
              }
   

     errorprior=error;


}
