#include "Motor.hpp"
#include <Arduino.h>

Motor::Motor(const int pin, int interval) 
    : pin_(pin), interval_(interval), previousMillis_(0), ledState_(LOW) {
    pinMode(pin_, OUTPUT);
}

Motor::~Motor() {
    digitalWrite(pin_, LOW);
}

void Motor::update() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis_ >= interval_) {
        previousMillis_ = currentMillis;
        ledState_ = !ledState_;
        digitalWrite(pin_, ledState_);
    }
}