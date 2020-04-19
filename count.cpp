#include <Arduino.h>

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 100;           // interval at which to blink (milliseconds)
unsigned int count = 0;

void setup() {
  //Serial.begin(9600);
  // set the digital pin as output:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    digitalWrite(2,  !((count & 0x1) >> 0));
    digitalWrite(3,  !((count & 0x2) >> 1));
    digitalWrite(4,  !((count & 0x4) >> 2));
    digitalWrite(5,  !((count & 0x8) >> 3));
    digitalWrite(6,  !((count & 0x10) >> 4));
    digitalWrite(7,  !((count & 0x20) >> 5));
    digitalWrite(8,  !((count & 0x40) >> 6));
    digitalWrite(9,  !((count & 0x80) >> 7));
    count++;
    //Serial.println( !((count & 0x1) >> 0));
    if (count == 256 )
      count = 0;
  }
}
