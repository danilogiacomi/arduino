#include <LiquidCrystal.h>

const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
 
 for(int j = 0; j < 2; j++) {
   for(int i = 0; i < 16; i++) {
     lcd.clear();
     lcd.setCursor(i,j);
     lcd.print(".");
     delay(500);
    }
  }

}
