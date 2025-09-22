
#include <Arduino.h>
#include "Blink.hpp"

Blink blink = Blink(2, 10);
Blink blinkb = Blink(33, 10);

void setup() {
  blink = Blink(2, 1);
  blinkb = Blink(33, 1);
  pinMode(32, OUTPUT);
  digitalWrite(32, HIGH);
}

void loop() {
  blink.update();
  blinkb.update();
} 