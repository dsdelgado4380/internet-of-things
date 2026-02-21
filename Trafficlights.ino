int LEDS[3] = {13, 12, 11}; 

void setup() {
  for(int r=0; r<3; r++){
    pinMode(LEDS[r], OUTPUT);
  }
}

void loop() {

  for(int r=0; r<3; r++){
    digitalWrite(LEDS[r], HIGH);
    delay(1000);
    digitalWrite(LEDS[r], LOW);
  }

  for(int r=1; r>0; r--){
    digitalWrite(LEDS[r], HIGH);
    delay(1000);
    digitalWrite(LEDS[r], LOW);
  }

}