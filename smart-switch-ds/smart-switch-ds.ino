#include<Servo.h>
#include <IRremote.h>
#include    <DigiUSB.h>

int RECV_PIN = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo;
int state = 0;

void setup(){
  DigiUSB.begin();
  servo.attach(5);
  //Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)){
      DigiUSB.println(results.value, HEX);
      DigiUSB.println("");
      irrecv.resume();
        if (results.value == 0xFFA25D || results.value == 0xE318261B){
          state = 1;
        }
   }
  if (state == 1){
      light();
      state = 0;
    }
  }

void light(){
  servo.write(0);
  delay(500);
  servo.write(100);  
  delay(500);
}
