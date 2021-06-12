#include <pitches.h>
 
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;  // 500 miliseconds
int i=0;

void setup() {
 
}
 
void loop() {  
  while(i < 1){
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
    // Output the voice after several minutes
    i += 1;
    delay(1000);
  }
}
