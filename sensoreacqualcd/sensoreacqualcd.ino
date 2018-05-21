
#include <LiquidCrystal.h>






const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);

}


void loop() {
  int sensorValue = analogRead(A0)
  // print out the value you read:
  Serial.println(sensorValue);
  delay(100);        
}

