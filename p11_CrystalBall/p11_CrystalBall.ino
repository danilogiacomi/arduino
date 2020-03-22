/*
  Arduino Starter Kit example
 Project 11  - Crystal Ball

 This sketch is written to accompany Project 11 in the
 Arduino Starter Kit

 Parts required:
 220 ohm resistor
 10 kilohm resistor
 10 kilohm potentiometer
 16x2 LCD screen
 tilt switch


 Created 13 September 2012
 by Scott Fitzgerald

 http://www.arduino.cc/starterKit

 This example code is part of the public domain
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(3,4,5,6,7,8);


// set up a constant for the tilt switchPin
const int switchPin = 0;

// variable to hold the value of the switchPin
int switchState = 0;

// variable to hold previous value of the switchpin
int prevSwitchState = 0;

// a variable to choose which reply from the crystal ball
int reply;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);

  // set up the switch pin as an input
  pinMode(switchPin, INPUT);
  chiedi();

  
}

void chiedi(){

//  lcd.autoscroll();
    // Print a message to the LCD.
  lcd.clear();
  lcd.print("Chiedi a");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("Crystal ball!");
  }

void loop() {
   
  /*
  
 
   // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 1; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
  }
  

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter <= 0; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(500);
  }
*/
  // delay at the end of the full loop:
  // delay(1000); 
 
  // check the status of the switch
  switchState = digitalRead(switchPin);

  // compare the switchState to its previous state
  //if (switchState != prevSwitchState) {

  if  ( switchState == LOW){
    
    // if the state has changed from HIGH to LOW
    // you know that the ball has been tilted from
    // one direction to the other
//    if (switchState == LOW) {
      // randomly chose a reply
      reply = random(12);
      // clean up the screen before printing a new reply
      lcd.clear();
      // set the cursor to column 0, line 0
      lcd.setCursor(0, 0);
      // print some text
      lcd.print("Crystal dice:");
      // move the cursor to the second line
      lcd.setCursor(0, 1);

      // choose a saying to print baed on the value in reply
      switch (reply) {
        case 0:
          lcd.print("Ok");
          break;

        case 1:
          lcd.print("Probabilmente");
          break;

        case 2:
          lcd.print("Molto sicuro");
          break;

        case 3:
          lcd.print("Probabilmente no");
          break;

        case 4:
          lcd.print("Incerto");
          break;

        case 5:
          lcd.print("Riprova");
          break;

        case 6:
          lcd.print("No");
          break;

         case 7:
          lcd.print("Forse");
          break;

         case 8:
          lcd.print("Bene");
          break;

         case 9:
          lcd.print("Male");
          break;

         case 10:
          lcd.print("Ottimo");
          break;

         case 11:
          lcd.print("Sono incerto");
          break;
      }
//    }

  delay(2000);
    chiedi();
  }

  
  // save the current switch state as the last state
//  prevSwitchState = switchState;
}

