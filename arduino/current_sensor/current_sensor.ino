//pin marking
int current = A1;
int voltage_R = A2;
int lm = A3;
int ldr_pin = 2;
int led_pin = 8;
float temp;

void setup(){
  pinMode(current,INPUT);
  pinMode(voltage_R,INPUT);
  pinMode(ldr_pin,INPUT);
  pinMode(lm, INPUT);
  pinMode(led_pin,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  //Current Sensor
  int adc = analogRead(current);
  float voltage = adc*5 / 1023.0;
  float current = (voltage-2.47)/0.1;
  
  //Voltage Sensor
  int signal_vol = analogRead(voltage_R);
  double voltage1 = map(signal_vol,0,1023,0,2700); 
  voltage1 = (voltage1/100);
  //delay(1000);
 
  //LDR
  if(digitalRead(ldr_pin)==1){
    digitalWrite(led_pin,HIGH);
  }
  else{
    digitalWrite(led_pin,LOW);
  }
  
  //LM35
  temp = analogRead(lm);
  temp = temp*(5.0/1024.0)*100;

  Serial.println((String)"\nCurrent: " + current + " Voltage: " + voltage1 + " LDR: " + digitalRead(ldr_pin) + " Temp: " + temp);
  delay(1000);   
  
}
