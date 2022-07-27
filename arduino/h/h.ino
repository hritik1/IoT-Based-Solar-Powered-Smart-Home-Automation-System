int i=0;

void setup(){
  Serial.begin(9600);
  Serial.println("Hello World");
}

void loop() {
  Serial.print("Counter = ");
  Serial.println(i++);
  delay(1000);
}
