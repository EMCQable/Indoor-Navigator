#include "Blink.hpp"
#include <Arduino.h>

Blink::Blink(const int pin, int interval) 
    : pin_(pin), interval_(interval), previousMillis_(0), ledState_(LOW) {
    pinMode(pin_, OUTPUT);
}

Blink::~Blink() {
    digitalWrite(pin_, LOW);
}

void Blink::update() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis_ >= interval_) {
        previousMillis_ = currentMillis;
        ledState_ = !ledState_;
        digitalWrite(pin_, ledState_);
    }
}