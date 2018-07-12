#include <LiquidCrystal.h>
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int alberto = 500;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.clear();
}

void loop() {
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("ciao Alberto! Arduino LCD Scroll.");
  lcd.setCursor(2,1);
  lcd.print("Trovi il codice nella scatola");
  for (int positionCounter = 0; positionCounter < 56; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(alberto);
  }

  for (int positionCounter = 0; positionCounter < 2
  ; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(alberto);
  }
  
  for (int positionCounter = 0; positionCounter < 55; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(alberto);
  }


}
