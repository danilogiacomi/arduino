#include <LiquidCrystal.h>

const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int w=4;
int ilValore;
String ilTesto;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void writeIt(String text, int value){
  
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print(text);
  
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("valore letto:");
  lcd.print(value);
 
}

void loop() {

  ilValore = analogRead(w);
     
  if(ilValore <= 300){ 
     ilTesto = "l'acqua e' bassa";
  }
  if(ilValore > 300 && ilValore < 600){ 
     ilTesto = "l'acqua e' media";
   }
  if(ilValore >= 600){ 
     ilTesto = "l'acqua e' alta!";
   }

  writeIt(ilTesto,  ilValore  );

   delay(2000);
 
}







