int smoke = A1;
int sensorThres = 400;

void setup() {
 Serial.begin(9600);
 pinMode(smoke, INPUT);
}
 
void loop() {
  int analog = analogRead(smoke);
  if(analog>sensorThres){
    Serial.print("HIGH\n");
    Serial.println("Vlaue: ");
    Serial.print(0.48828125*analog);
  }
  else{
    Serial.print("\nLOW :\n");
    Serial.println("Vlaue: ");
    Serial.print(0.48828125*analog);
  }
  delay(1000);
  
} 
