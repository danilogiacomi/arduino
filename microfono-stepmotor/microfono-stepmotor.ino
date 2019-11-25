#include <Stepper.h>
int stepmotor = 13;
int buttonpin = 3;
int val = 0;

const int stepsPerRevolution = 700;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 12); 

void setup () {
  pinMode (stepmotor, OUTPUT);
  pinMode (buttonpin, INPUT);
}

void loop () {
  val = digitalRead(buttonpin);
  Serial.print (val);
  if (val == HIGH) {
    digitalWrite (stepmotor, HIGH);
    int sensorReading = analogRead(A0);
    int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
    if (motorSpeed > 0) {
     myStepper.setSpeed(motorSpeed);
     myStepper.step(stepsPerRevolution / 100);
    }
  }
  else {
    digitalWrite (stepmotor, LOW);
  }
}

/*
 * Codice originale Step Motor:
 * #include <Stepper.h>
 * const int stepsPerRevolution = 700;
 * Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
 * 
 * int stepCount = 0;
 * 
 * void setup() {
 * }
 * 
 * void loop() {
 *  int sensorReading = analogRead(A0);
 *  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
 *  if (motorSpeed > 0) {
 *   myStepper.setSpeed(motorSpeed);
 *   myStepper.step(stepsPerRevolution / 100);
 *  }
 * }
 */
