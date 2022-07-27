int pulse = A0;

void setup(){
  Serial.begin(9600);
  pinMode(pulse,INPUT);
}
void loop(){
  Serial.println(analogRead(pulse));
}
