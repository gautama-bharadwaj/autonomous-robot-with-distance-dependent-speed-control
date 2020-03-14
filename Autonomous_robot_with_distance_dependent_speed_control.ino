#define trigPin 13
#define echoPin 12
int E1=5;
int E2=6;
int IN1=9;
int IN2=11;
int IN3=7;
int IN4=3;
int LED=A0;
int duration, distance;

void setup() {
 Serial.begin(9600);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(IN1, OUTPUT);        //Declaring input pins from the controller
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(E1, OUTPUT);          //Declaring pins for power supply
 pinMode(E2, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(A0,OUTPUT);//Declaring pin for LED
 pinMode(8,OUTPUT); //Declaring pin for buzzer
 digitalWrite(4, HIGH);//Power and ground for motor driver
 digitalWrite(2,LOW); 
}

void loop() {
    digitalWrite(A0,LOW);
    digitalWrite(trigPin, HIGH);       //Trigerring the pin to send waves
    delayMicroseconds(100);           
    digitalWrite(trigPin, LOW);              
    duration = pulseIn(echoPin, HIGH); //Detecting the duration of receiving the wave
    distance = (duration/2) / 29.1;
    Serial.print(distance);
    Serial.print("\n");
    delay(50);
  if(distance>60)                       //Code for controlling motor start
  {
    analogWrite(E1,255);
    analogWrite(E2,255);
    forward();
  }
 
  if(distance>30&&distance<60)
  {
    analogWrite(E1,170);
    analogWrite(E2,170);
    forward();
  }
  if(distance<30)
  {
      analogWrite(E1,0);
      analogWrite(E2,0);    //Code for controlling motor end
      forward();
  }                      
  if(distance>30&&distance<60)         //Code for controlling buzzer start
  {
    tone(8,4000);
  }
  if(distance<=30)
  {
    noTone(8);
  }              
  if(distance>60)
  {
    noTone(8);//Code for controlling buzzer end
  }
  if(distance<=60&&distance>30)
  {
    digitalWrite(A0,HIGH);
    delay(100);
    digitalWrite(A0,LOW);
  }
  else
  {
    digitalWrite(A0,LOW);
  }
}
void forward()
{
     digitalWrite(IN1, LOW);
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
}
