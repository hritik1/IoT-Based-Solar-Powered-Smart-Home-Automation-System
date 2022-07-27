#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h> 
                               
PulseSensorPlayground pulseSensor; 

int Threshold = 500;

void setup() {   
  Serial.begin(9600); 

  pulseSensor.analogInput(0);   

  pulseSensor.setThreshold(Threshold);   
 
  if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");   
  }
}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute(); 
  if (pulseSensor.sawStartOfBeat()) { 
    Serial.println("♥  A HeartBeat Happened ! "); 
    Serial.print("BPM: "); 
    Serial.println(myBPM);
  }
  delay(20); 
}
