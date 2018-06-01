#include <LiquidCrystal.h>
long randNumber;
long unsigned int lowIn;         
boolean lockLow = true;
boolean takeLowTime;  
int pirPin = 10;  
const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int tempoAspetta = 2000;
  
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);
}

void loop() {
  randNumber = random(999999);
  lcd.clear();
   
  if(digitalRead(pirPin) == HIGH){
    lcd.print("tu sei il numero");
    lcd.setCursor(5,5);
    lcd.print(randNumber);
  }
    
   if(digitalRead(pirPin) == LOW){     
     lcd.setCursor(1,0);
     lcd.print("generatore di");
     lcd.setCursor(1,1);
     lcd.print("numeri casuali");
   }
   delay(tempoAspetta);
 
}


