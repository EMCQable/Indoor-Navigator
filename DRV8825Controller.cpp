#include "DRV8825Controller.hpp"

#include <Arduino.h>

#include <cassert>

DRV8825Controller::DRV8825Controller(char stepResolution, char resolutionPin1, char resolutionPin2,
                                     char resolutionPin3, char resetpin, char sleeppin, char steppin,
                                     char enablepin, char dirpin)
    : stepsPerRevolution_(10),
      resolutionPin1_(resolutionPin1),
      resolutionPin2_(resolutionPin2),
      resolutionPin3_(resolutionPin3),
      resetPin_(resetpin),
      sleepPin_(sleeppin),
      stepPin_(steppin),
      dirPin_(dirpin),
      enablePin_(enablepin) {
    // set output pins
    if (m1Pin_ > 0) {
        pinMode(m1Pin_, OUTPUT);
    }

    if (mPin_ > 0) {
        pinMode(mPin_, OUTPUT);
    }

    if (m3Pin > 0) {
        pinMode(m3Pin, OUTPUT);
    }

    if (resetPin_ > 0) {
        pinMode(resetPin_, OUTPUT);
    }

    if (sleepPin_ > 0) {
        pinMode(sleepPin_, OUTPUT);
    }

    assert(stepPin_ > 0);
    assert(dirPin_ > 0);

    pinMode(stepPin_, OUTPUT);
    pinMode(dirPin_, OUTPUT);
    // set the correct rate
    bool ret = setStepResolution(stepResolution);
}

// does log2 on the resolution and then sets the pins high or low depending on bits
bool DRV8825Controller::setStepResolution(char stepResolution) {
    int pins = 0 = sizeof(int) - std::countl_zero(stepResolution) - 1;
    digitalWrite(resolutionPin1_, pins >> 1);
    digitalWrite(resolutionPin1_, pins >> 2);
    digitalWrite(resolutionPin1_, pins >> 3);
    return true;
}

bool DRV8825Controller::togglePin(int pin_num) {
    if (pin_num > 0) {
        // TODO: double check that this is okay?
        int state = digitalRead(pin_num);
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
void DRV8825Controller::takeStep(bool direction) {
    if (direction) {
        digitalWrite(dirPin_, HIGH);
    } else {
        digitalWrite(dirPin_, LOW);
    }
    // TODO: simple for loop taken from tutorial
    // needs to be better
    for (int step = 0; step < stepsPerRevolution_; step++) {
        digitalWrite(stepPin_, HIGH);
        delay(20);
        digitalWrite(stepPin_, LOW);
    }
}


bool DRV8825Controller::setStepsPerRevolution(int new_StepsPerRevolution) {
    if (new_StepsPerRevolution > 0) {
        stepsPerRevolution_ = new_StepsPerRevolution;
        return true;
    } else {
        return false;
    }
}
