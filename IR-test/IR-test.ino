#include <IRremote.h>

int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;
int LED_state = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LED_BUILTIN, OUTPUT);
}

String decode_txt[] = {"UNUSED", "BOSEWAVE", "DENON", "DISH", 
                       "JVC", "LEGP_PF", "LG", "MAGIQUEST", 
                       "NEC_STANDARD", "NEC", "PANASONIC", "RC5", 
                       "RC6", "SAMSUNG", "SANYO", "SHARP", 
                       "SHARP_ALT", "SONY", "WHYNTER"};

void loop()
{
  if (irrecv.decode(&results))
  {
      Serial.println(results.value);
      Serial.println("");
      irrecv.resume();
  }
  if (results.value == 0xFFA25D){
          LED_state = 1; 
        }else if(results.value == 0xFF22DD){
          LED_state = 0;
        }
      Serial.println(LED_state);
      
  if(LED_state == 1){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000); 
  } else{
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(1000); 
  }
}
