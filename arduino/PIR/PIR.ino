int sensor = 2;

void setup(){
  Serial.begin(9600);
  pinMode(sensor,INPUT);
}

void loop(){
  int sensorVal = digitalRead(sensor);
  Serial.println(sensorVal);
  delay(1000);
}
