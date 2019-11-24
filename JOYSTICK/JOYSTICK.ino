int xVal;
int yVal;
int clickk;


void setup(){
 Serial.begin(9600);
 
 pinMode(4, INPUT);
 pinMode(2, INPUT);
 pinMode(8, INPUT);
}


void loop(){
 xVal = digitalRead(2);
 yVal = digitalRead(4);
 clickk = digitalRead(8);
 
 if (xVal != 180){
  Serial.print(" X ");
  Serial.print(xVal);
 }
 
 if (yVal != 180){
  Serial.print(" Y ");
  Serial.print(yVal);
 }
 
 if (clickk != 0){
  Serial.print("hai premuto il bottone!");
 }
}
