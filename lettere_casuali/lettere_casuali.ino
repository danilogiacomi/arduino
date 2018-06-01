#include <LiquidCrystal.h>
long randNumber;
const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int tempoAspetta = 5000;
int numberLetter = randNumber%25;
const char l0 = 'q';
const char l1 = 'w';
const char l2 = 'e';
const char l3 = 'r';
const char l4 = 't';
const char l5 = 'y';
const char l6 = 'u';
const char l7 = 'i';
const char l8 = 'o';
const char l9 = 'p';
const char l10 = 'a';
const char l11 = 's';
const char l12 = 'd';
const char l13 = 'f';
const char l14 = 'g';
const char l15 = 'h';
const char l16 = 'j';
const char l17 = 'k';
const char l18 = 'l';
const char l19 = 'z';
const char l20 = 'x';
const char l21 = 'c';
const char l22 = 'v';
const char l23 = 'b';
const char l24 = 'n';
const char l25 = 'm';

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  randNumber = random(25);
  lcd.clear();
  switch (numberLetter) {
  case 0:
   lcd.print(l0);
    break;
   case 1:
   lcd.print(l1);
    break;
     case 2:
   lcd.print(l2);
    break;
     case 3:
   lcd.print(l3);
    break;
     case 4:
   lcd.print(l4);
    break;
     case 5:
   lcd.print(l5);
    break;
     case 6:
   lcd.print(l6);
    break;
     case 7:
   lcd.print(l7);
    break;
     case 8:
   lcd.print(l8);
    break;
     case 9:
   lcd.print(l9);
    break;
     case 10:
   lcd.print(l10);
    break;
     case 11:
   lcd.print(l11);
    break;
     case 12:
   lcd.print(l12);
    break;
     case 13:
   lcd.print(l13);
    break;
     case 14:
   lcd.print(l14);
    break;
     case 15:
   lcd.print(l15);
    break;
     case 16:
   lcd.print(l16);
    break;
     case 17:
   lcd.print(l17);
    break;
     case 18:
   lcd.print(l18);
    break;
     case 19:
   lcd.print(l19);
    break;
     case 20:
   lcd.print(l20);
    break;
     case 21:
   lcd.print(l21);
    break;
     case 22:
   lcd.print(l22);
    break;
     case 23:
   lcd.print(l23);
    break;
     case 24:
   lcd.print(l24);
    break;
     case 25:
   lcd.print(l25);
    break;
  default:
    lcd.print("errore");
    break;
  }
  delay(tempoAspetta);  
}


