int smokeA0 = A2;
int sensorThres = 400;

void setup() {
 Serial.begin(9600);
 pinMode(smokeA0, INPUT);
}
 
void loop() {
  int analog = analogRead(A0);
  if(analog>sensorThres){
    Serial.print("HIGH\n");
    Serial.println("Vlaue: ");
    Serial.print(analog);
  }
  else{
    Serial.print("\nLOW :\n");
    Serial.println("Vlaue: ");
    Serial.print(analog);
  }
  delay(1000);
  
} 
