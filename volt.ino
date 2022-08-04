#include "lgtx8p.h"

void setup() {
  //set D13 to output
  fastioMode(D6, OUTPUT); // red
  fastioMode(D8, OUTPUT); // green
  analogReadResolution(12);
  pinMode(A6, INPUT);

  Serial.begin(57600);

  fastioWrite(D6, LOW);
  fastioWrite(D8, HIGH);
}

void loop() {
  delay(500); 
  int readValue = analogRead(A6);
  Serial.println(readValue);
  if(readValue > 528){
    fastioWrite(D6, LOW);
    fastioWrite(D8, HIGH);
  }
  if(readValue < 527){  
    fastioWrite(D8, LOW);
    fastioWrite(D6, HIGH);
  } 
}
