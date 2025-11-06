#include "DRV8825Controller.hpp"

#include <Arduino.h>

#include <cassert>
#include <bit>

DRV8825Controller::DRV8825Controller(char stepResolution, char resolutionPin1, char resolutionPin2,
                                     char resolutionPin3, char resetPin, char sleepPin,
                                     char motorPin, char enablePin, char dirPin, char pwmChannel)
    : motor_(motorPin, pwmChannel),
      resolutionPin1_(resolutionPin1),
      resolutionPin2_(resolutionPin2),
      resolutionPin3_(resolutionPin3),
      resetPin_(resetPin),
      sleepPin_(sleepPin),
      motorPin_(motorPin),
      dirPin_(dirPin),
      enablePin_(enablePin)

{
    // set output pins
    if (resolutionPin1 > 0) {
        pinMode(resolutionPin1_, OUTPUT);
    }

    if (resolutionPin2_ > 0) {
        pinMode(resolutionPin2_, OUTPUT);
    }

    if (resolutionPin3_ > 0) {
        pinMode(resolutionPin3_, OUTPUT);
    }

    if (resetPin_ > 0) {
        pinMode(resetPin_, OUTPUT);
    }

    if (sleepPin_ > 0) {
        pinMode(sleepPin_, OUTPUT);
    }

    assert(motorPin_ > 0);
    assert(dirPin_ > 0);

    pinMode(motorPin_, OUTPUT);
    pinMode(dirPin_, OUTPUT);
    // set the correct rate
    bool ret = setStepResolution(stepResolution);
}

// maps 1, 2, 4, 8, 16, 32 to 0, 1, 2, 3, 4, 5 and sets pins according to bits
bool DRV8825Controller::setStepResolution(unsigned int stepResolution) {
    unsigned int pins = 0;
    pins = sizeof(int) - std::countl_zero(stepResolution) - 1;
    digitalWrite(resolutionPin1_, pins & 0b001);
    digitalWrite(resolutionPin2_, pins & 0b010);
    digitalWrite(resolutionPin3_, pins & 0b100);
    return true;
}

bool DRV8825Controller::togglePin(int pin_num) {
    if (pin_num > 0) {
        // TODO: double check that this is okay?
        const int state = digitalRead(pin_num);
        if (state == LOW) {
            digitalWrite(pin_num, HIGH);
        } else {
            digitalWrite(pin_num, LOW);
        }
        return true;
    } else {
        return false;
    }
}

bool DRV8825Controller::toggleReset() { return togglePin(resetPin_); }

bool DRV8825Controller::toggleSleep() { return togglePin(sleepPin_); }

bool DRV8825Controller::toggleEnable() { return togglePin(enablePin_); }

// if direction is true or 1 or HIGH, clockwise direction
// if direction is false or 0 or LOW, counter clockwise direction
void DRV8825Controller::setSpeed(bool direction, char motorSpeed) {
    if (direction) {
        digitalWrite(dirPin_, HIGH);
    } else {
        digitalWrite(dirPin_, LOW);
    }
    motor_.setSpeed(motorSpeed);
}