#include <LiquidCrystal.h>

const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// modificare i valori per cambiare la velocità
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
  lcd.begin(16,2);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
puntinoBarretta();
}
