#include <dht.h>
#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT;
 
int Pulse = A2;
int LM = A1;
int humdTY = A3;   
int fan2 = 13;

void setup(){
  Serial.begin(9600);
  pinMode(Pulse,INPUT);
  pinMode(LM,INPUT);
  pinMode(humdTY ,INPUT);
  lcd.begin(16,2);
 }


void loop(){
  int lm = analogRead(LM);
  int chk = DHT.read11(humdTY);
  int pulse = analogRead(Pulse);

  //fan2
  if(DHT.temperature > 32){
    analogWrite(fan2,1023);
  }
  else if(DHT.temperature >= 23 && DHT.temperature < 32){
    analogWrite(fan2,300);
  }
  
  //Lm35 Temp
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Body Temperature");
  lcd.setCursor(0,1);
  lcd.print(0.48828125*lm);
  delay(2000);
  
  //DHT Temp
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Room Temperature");
  lcd.setCursor(0,1);
  lcd.print(DHT.temperature);
  delay(2000);
  
  //DHT Humidity
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity");
  lcd.setCursor(0,1);
  lcd.print(DHT.humidity);
  delay(2000);
  
  //DHT Humidity
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pulse");
  lcd.setCursor(0,1);
  lcd.print(pulse);
  delay(2000);
}
