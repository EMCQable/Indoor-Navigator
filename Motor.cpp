#include "Motor.hpp"

#include <Arduino.h>

Motor::Motor(const int motorPin, int freq, int resolution, int channel)
    : motorPin_(motorPin), channel_(channel), previousMillis_(0), ledState_(LOW) {
    ledcAttachChannel(motorPin, freq, resolution, channel);
}
Motor::Motor(const int motorPin, int channel) motorPin_(motorPin), channel_(channel),
    previousMillis_(0), ledState_(LOW) {
    ledcAttachChannel(motorPin, 0, 255, channel);
}

Motor::~Motor() { ledcWrite(motorPin_, 0); }
// Naive approach which assumes the program will always return to the function.
// TODO: Add functionality to ensure motor will not be left running, timeout etc.
void Motor::setSpeed(char newSpeed) { ledcWrite(motorPin_, newSpeed); }
