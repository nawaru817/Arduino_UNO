#include <pitches.h>
 
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;  // 500 miliseconds
int i=0;

void setup() {
 
}
 
void loop() {  
  while(i < 3){
    tone(8, NOTE_C5, duration);
    i += 1;  
    // Output the voice after several minutes
    delay(1000);
  }
}
