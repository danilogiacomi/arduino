#include <LiquidCrystal.h>

const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int w=4;
int ilValore;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {

  ilValore = analogRead(w);

  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
     
  if(ilValore <= 300){ 
     lcd.print("l'acqua e' bassa");
   }
  if(ilValore > 300 && ilValore < 600){ 
     lcd.print("l'acqua e' media");
   }
  if(ilValore >= 600){ 
     lcd.print("l'acqua e' alta!");
   }
 
   lcd.setCursor(0,1);
   lcd.print("                ");
   lcd.setCursor(0,1);
   lcd.print(ilValore);
   
   delay(1000);
 
}
