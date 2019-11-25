int stepmotor = 13;
int buttonpin = 3;
int val = 0;
 
void setup ()
{
  pinMode (stepmotor, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// output interface D0 is defined sensor
}
 
void loop ()
{
  val = digitalRead(buttonpin);
  Serial.print (val);
  if (val == HIGH) // When the sound detection module detects a signal, LED flashes
  {
    digitalWrite (stepmotor, HIGH);
  }
  else
  {
    digitalWrite (stepmotor, LOW);
  }
  delay (100);
}
