#include "DRV8825Controller.hpp"
#include <Arduino.h>
#include <cassert>

DRV8825Controller::DRV8825Controller( 
        int turnratedenominator, int m1pin, int m2pin, int m3pin,
        int resetpin, int sleeppin, int steppin, int enablepin, int dirpin) : 
    stepsPerRevolution_(10), m1Pin_(m1pin), mPin_(m2pin), m3Pin_(m3pin), resetPin_(resetpin),
    sleepPin_(sleeppin), stepPin_(steppin), dirPin_(dirpin), enablePin_(enablepin) {
        // set output pins
        if (m1Pin_ > 0) {
            pinMode(m1Pin_, OUTPUT);
        }

        if (mPin_ > 0) {
            pinMode(mPin_, OUTPUT);
        }

        if (m3Pin_ > 0) {
            pinMode(m3Pin_, OUTPUT);
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
        bool ret = setStepMode(turnratedenominator);
}

bool DRV8825Controller::setStepMode(int denominator) {
        switch (denominator)
        {
            case 1:
                if (mPin_ > 0){
                    digitalWrite(mPin_,LOW);
                }
                if (m3Pin_ > 0) {
                    digitalWrite(m3Pin_,LOW);
                }
                if (m1Pin_ > 0){
                    digitalWrite(m1Pin_,LOW);
                }
                return true;
                break;
            case 2:
                if (m1Pin_ > 0){
                    digitalWrite(m1Pin_,HIGH);
                } else {
                    return false;
                }
                if (mPin_ > 0){
                    digitalWrite(mPin_,LOW);
                }
                if (m3Pin_ > 0) {
                    digitalWrite(m3Pin_,LOW);
                }
                return true;
                break;
            case 4:
                if (m1Pin_ > 0) {
                    digitalWrite(m1Pin_,LOW);
                }
                if (mPin_ > 0) {
                    digitalWrite(mPin_,HIGH);
                } else {
                    return false;
                }
                if (m3Pin_ > 0) {
                    digitalWrite(m3Pin_,LOW);
                }
                return true;
                break;
            case 8:
                if (m1Pin_ > 0) {
                    digitalWrite(m1Pin_,HIGH);
                } else{
                    return false;
                }
                if (mPin_ > 0) {
                    digitalWrite(mPin_,HIGH);
                } else {
                    return false;
                }
                if (m3Pin_ > 0) {
                    digitalWrite(m3Pin_,LOW);
                }
                return true;
                break;
            case 16:
                if (m1Pin_ > 0) {
                    digitalWrite(m1Pin_,LOW);
                }
                if (mPin_ > 0) {
                    digitalWrite(mPin_,LOW);
                } else {
                    return false;
                }
                if (m3Pin_ > 0) {
                    digitalWrite(m3Pin_,HIGH);
                } else {
                    return false;
                }
                return true;
                break;
            case 32:
                // TODO: there could be better if loop to go through all possibilities
                // for example, M1 HIGH, M2 HIGH and M3 HIGH
                if (m1Pin_ > 0) {
                    digitalWrite(m1Pin_,HIGH);
                } else {
                    return false;
                }
                if (mPin_ > 0) {
                    digitalWrite(mPin_,LOW);
                } 
                if (m3Pin_ > 0) {
                    digitalWrite(m3Pin_,HIGH);
                } else {
                    return false;
                }
                return true;
                break;
            default:
                // keep same
                break;
        }
        return false;
}

bool DRV8825Controller::togglePin(int pin_num) {
    if (pin_num > 0 ) {
        // TODO: double check that this is okay? 
        int state = digitalRead(pin_num);
        if (state == LOW) {
            digitalWrite(pin_num,HIGH);
        } else {
            digitalWrite(pin_num,LOW);
        }
        return true;
    } else {
        return false;
    }
}

bool DRV8825Controller::toggleReset() {
    return togglePin(resetPin_);
}

bool DRV8825Controller::toggleSleep() {
    return togglePin(sleepPin_);
}

bool DRV8825Controller::toggleEnable() {
    return togglePin(enablePin_);
}

// if direction is true or 1 or HIGH, clockwise direction
// if direction is false or 0 or LOW, counter clockwise direction
void DRV8825Controller::takeStep(bool direction) {
    if (direction) {
        digitalWrite(dirPin_,HIGH);
    } else {
        digitalWrite(dirPin_,LOW);
    }
    // TODO: simple for loop taken from tutorial
    // needs to be better
    for (int x = 0; x < stepsPerRevolution_; x++) {
        digitalWrite(stepPin_,HIGH);
        delay(20);
        digitalWrite(stepPin_,LOW);
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
