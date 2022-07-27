#include <dht.h>

dht DHT;

#define temp 2

void setup() {
 Serial.begin(9600);
}
  
void loop() {
  int chk = DHT.read11(temp);
  Serial.print("Temperature :");
  Serial.println(DHT.temperature);
  Serial.print("Humidity :");
  Serial.println(DHT.humidity);
  delay(2000);
}
