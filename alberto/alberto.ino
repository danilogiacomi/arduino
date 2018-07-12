#include <LiquidCrystal.h>
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int alberto = 500;
const int puntinoSpeed = 300;
const int titoliSpeed = 500;
const char c1 = '-';
const char c2 = '/';
const char c3 = '|';
const char c4 = '#';
const char cd = '.';

void drawCarattere(int x, int y, char carattere, bool wait = true){
   lcd.clear();
   lcd.setCursor(x,y);
   lcd.print(carattere);
   if (wait){
     delay(puntinoSpeed);
   } 
}


void puntinoBarretta(){
  char c;
  bool wait = true;
  int resto;
  for(int j = 0; j <= 1; j++) {
      for(int i = 0; i <= 15; i++) {     
         // wait = (i != 15) || (j != 1);
          resto = i%4;
          switch (resto) {
            case 0:
              c = c1;
              break;
            case 1:
              c = c2;
              break;
            case 2:
              c = c3;
              break;
            case 3:
              c = c4;
              break;
            default:
              c = cd;
          }
          
          drawCarattere(i,j, c,  wait);
      }
   }
}


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Hi Albi! Trovi il codice nella scatola");
    for (int positionCounter = 0; positionCounter < 31; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(alberto);
    }
}

void loop() {

 lcd.clear();  
 puntinoBarretta();
 
 
}
