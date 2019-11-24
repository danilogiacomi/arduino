int xVal;
int yVal;


void setup() {
Serial.begin(300);
pinMode(A0, INPUT);
pinMode(A2, INPUT);
}


void loop() {
xVal = analogRead(A0);
yVal = analogRead(A2);
Serial.print("Valore Y");
Serial.print(yVal); 
Serial.print(" ");
Serial.print("Valore X");
Serial.print(xVal);
Serial.print(" ");
delay(10000);
}
