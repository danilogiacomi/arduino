#include <LiquidCrystal.h>






const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);

}
void loop() {

  for (int positionCounter = 0; positionCounter <50; positionCounter++) {
    delay(300);//no
  
  lcd.setCursor(0,0);
  lcd.print("ci facciamo una partita a pokgemon?");
  lcd.setCursor(8,1);
  lcd.print("dai di' di si'");

  


  }
}
