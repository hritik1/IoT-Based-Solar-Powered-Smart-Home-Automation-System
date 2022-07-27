float temp; //internal variable

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(A2);
  temp = temp*(5.0/1024.0)*100; 
  Serial.print("\nTemperature: ");
  Serial.print(temp);
  Serial.print("*C\n");

  delay(1000);
}
