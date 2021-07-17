#include<Servo.h>
#include <IRremote.h>
#include <avr/wdt.h>

int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo;
int state = 0;

void setup(){
  servo.attach(2);
  servo.write(0);
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.print("再開");
}


void loop() {
  if (irrecv.decode(&results)){
      Serial.println(results.value, HEX);
      Serial.println("");
      irrecv.resume();
        if (results.value == 0xFFA25D || results.value == 0xE318261B){
          state = 1;
        }
   }
  if (state == 1){
      light();
      state = 0;
      software_reset();
    }
  }

void software_reset() {
  wdt_disable();
  wdt_enable(WDTO_15MS);
  Serial.print("リセットしました");
}


void light(){
  servo.write(33);
  delay(500);
  servo.write(0);  
  delay(500);
}
