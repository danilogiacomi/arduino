
  

// include the library code:
#include <LiquidCrystal.h>
long unsigned int lowIn;         
 
boolean lockLow = true;
boolean takeLowTime;  
 
int pirPin = 10; 
int ledPinrosso = 13;//primasetup
int ledPinverde = 12;//primasetup 
int ledPinblu = 11;//primasetup 

 


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  
  digitalWrite(pirPin, LOW);
  pinMode(ledPinverde, OUTPUT);//setup
  pinMode(ledPinrosso, OUTPUT);//setup
  pinMode(ledPinblu, OUTPUT);//setup
 
  /*for (int i = 0; i < buzPin; i++) 
    {
 }
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
 */
}

void loop() {
 /* // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0,0);
  // Print a message to the LCD.
  lcd.print("movimento");
 
 
 for (int positionCounter = 0; positionCounter <50; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
*/






    if(digitalRead(pirPin) == HIGH){
      lcd.setCursor(0,0);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("                ");
      digitalWrite(ledPinrosso, HIGH);
      digitalWrite(ledPinblu, HIGH);
      digitalWrite(ledPinverde, LOW);
     // lcd.setCursor(0,0);
     // lcd.print("benvenuti a casa");
     // lcd.setCursor(5,5);
      //lcd.print("nostra");
      lcd.setCursor(0,1);
      lcd.print("benvenuti a casa nostra");
      }


        /*for (int positionCounter = 0; positionCounter <50; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);//no
    */
    delay(200);
        
 
     if(digitalRead(pirPin) == LOW){
      lcd.setCursor(0,0);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("                ");
      digitalWrite(ledPinverde, HIGH);
      digitalWrite(ledPinrosso, LOW);
      digitalWrite(ledPinblu, LOW );         
      lcd.setCursor(1,2);
      lcd.print("20 maggio 2018");
      //lcd.setCursor(10,2);
    //  lcd.print("scritto da ");
      //lcd.setCursor(11,0);
      //lcd.print(millis() / 1000);
     }
  }


  //delay(1000);
     
 


  
  /*
   * 
   // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(300);
    }

  delay(1000);

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
  }
  
  delay(1000);

  // delay at the end of the full loop:
  delay(1000);

*/

//}

