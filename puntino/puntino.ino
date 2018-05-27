#include <LiquidCrystal.h>

const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void drawPuntino(int x, int y, bool wait = true){
     lcd.clear();
     lcd.setCursor(x,y);
     lcd.print(".");
     if (wait){
       delay(300);
     } 
  }
  
void loop() {

 
  for(int j = 0; j < 2; j++) {
     for(int i = 0; i < 16; i++) {
        bool wait = (i != 15) || (j != 1);
        drawPuntino(i,j, wait);
     }
  }

  for(int j = 1; j >= 0; j--) {
    for(int i = 15; i >= 0; i--) {
      drawPuntino(i,j);
     }
   }

}
