#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 10

const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop() {
/*
for (int i=80;i<256;i++){
  lcd.setCursor(0,0); 
  lcd.print(i);

  lcd.setCursor(0,1); 
  lcd.print((char)i);
  delay(300);
}
  */



  
  // put your main code here, to run repeatedly:
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Umidita': ");
  //lcd.print((char)224);
  //lcd.print(": ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1000);

  
}
