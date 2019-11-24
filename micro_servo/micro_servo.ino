#include <Servo.h>

int i = 0;
int j = 0;
int k = 0;
int f = 0;

Servo servo_3;

void setup(){
  servo_3.attach(3);
}

void loop(){
  for (i = 0; i <= 120; i += 1) {
    servo_3.write(i);
    delay(50); 
}

  for (k = 120; k >= 0; k -= 1) {
    servo_3.write(k);
    delay(50);
  }

  for (j = 30; j >= 0; j += 1) {
    servo_3.write(j);
    delay(50);
  }
  for (f = 30; f >= 0; f -= 1) {
    servo_3.write(f);
    delay(50);
  }
}
