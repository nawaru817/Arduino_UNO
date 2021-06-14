#include <pitches.h>
#include <SR04.h>
#define TRIG_PIN 13
#define ECHO_PIN 12
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;


void setup() {
   Serial.begin(9600);
   delay(1000);
   pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(1000);
   if(a < 5){
    solitude();
   }
}

void solitude() {  
    tone(8, NOTE_D6, 400);
    delay(400);
    tone(8, NOTE_G6, 400);
    delay(400);
    tone(8, NOTE_D7, 400);
    delay(400);
    tone(8, NOTE_A5, 400);
    delay(400);
    tone(8, NOTE_B5, 200);
    delay(200);
    tone(8, NOTE_D6, 400);
    delay(400);
    tone(8, NOTE_G5, 400);
    delay(400);
    tone(8, NOTE_A5, 800);

    delay(1000);
}
