#include<Servo.h>
#include <dht.h>
Servo motor;
dht DHT;

//sensor pins
int p=90;
int PIR = 2; 
int irPin2=3;
int irPin1=4;  
int ServoMotor = 5;
int LED = 6;
int fan1 = 7;


int MQ = A2;

//Mq2 threshold
int sensorThres = 400;

// bidirectional counter variable
int count=0;

void setup(){
  Serial.begin(9600);
  pinMode(irPin1,INPUT);
  pinMode(irPin2,INPUT);
  pinMode(PIR,INPUT);
  pinMode(MQ,INPUT);
  motor.attach(ServoMotor);
  motor.write(0);
}


void loop(){
  int in_val = digitalRead(irPin2);
  int out_val = digitalRead(irPin1);
  
  delay(500);

  if (in_val == LOW){
    count++;
    Serial.println((String)"count in room : " + count);
  
    for (p=0;p<90;p++){
    motor.write(p);}
    delay(1000);

    for (p=90;p>0;p--){
    motor.write(p);}
  }

  if (out_val == LOW){
    count--;
    Serial.println((String)"count in room : " + count);
    
    for (p=0;p<90;p++){
    motor.write(p);}
    delay(1000);

    for (p=90;p>0;p--){
    motor.write(p);}
  }

  if (count <= 0){
    Serial.println((String)"Count in Room : " + count);
    delay(1000);
  }
  
  //Smoke
  int smkAlt = 0; 
  if(analogRead(MQ) > sensorThres){
    analogWrite(fan1,1023);
    smkAlt = 1;
  }

  if(smkAlt == 1){
    //Serial.println((String)"Gas Leakage in Kitchen! Alert!");
  }
  //Light
  int alert = 0;
  if(digitalRead(PIR) == 1){
    digitalWrite(LED,HIGH);
    alert = 1;
  }
  else{
    digitalWrite(LED,LOW);
  }

  if(count <= 0 && alert == 1){
    //Serial.println((String)"Intruder! Alert");
  }
 
}
