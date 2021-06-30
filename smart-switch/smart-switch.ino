#include<Servo.h>
#define SERVO_PIN 5

Servo servo;

void setup(){
    servo.attach(SERVO_PIN);
}

void loop() {
  servo.write(0);
  delay(500);
  servo.write(100);  
  delay(500);
}
