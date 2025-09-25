#include "DRV8825Controller.hpp"
#include <Arduino.h>
#include <cassert>

ProjectStepControl::ProjectStepControl( 
        int turnratedenominator, int m1pin, int m2pin, int m3pin,
        int resetpin, int sleeppin, int steppin, int enablepin, int dirpin) : 
    StepsPerRevolution(10), M1Pin(m1pin), M2Pin(m2pin), M3Pin(m3pin), ResetPin(resetpin),
    SleepPin(sleeppin), StepPin(steppin), DirPin(dirpin) {
        // set output pins
        if (M1Pin > 0) {
            pinMode(M1Pin, OUTPUT);
        }

        if (M2Pin > 0) {
            pinMode(M2Pin, OUTPUT);
        }

        if (M3Pin > 0) {
            pinMode(M3Pin, OUTPUT);
        }

        if (ResetPin > 0) {
            pinMode(ResetPin, OUTPUT);
        }

        if (SleepPin > 0) {
            pinMode(SleepPin, OUTPUT);
        }

        assert(StepPin > 0);
        assert(DirPin > 0);

        pinMode(StepPin, OUTPUT);
        pinMode(DirPin, OUTPUT);
        // set the correct rate
        bool ret = SetStepMode(turnratedenominator);
}

bool ProjectStepControl::SetStepMode(int denominator) {
        switch (denominator)
        {
            case 1:
                if (M2Pin > 0){
                    digitalWrite(M2Pin,LOW);
                }
                if (M3Pin > 0) {
                    digitalWrite(M3Pin,LOW);
                }
                if (M1Pin > 0){
                    digitalWrite(M1Pin,LOW);
                }
                return true;
                break;
            case 2:
                if (M1Pin > 0){
                    digitalWrite(M1Pin,HIGH);
                } else {
                    return false;
                }
                if (M2Pin > 0){
                    digitalWrite(M2Pin,LOW);
                }
                if (M3Pin > 0) {
                    digitalWrite(M3Pin,LOW);
                }
                return true;
                break;
            case 4:
                if (M1Pin > 0) {
                    digitalWrite(M1Pin,LOW);
                }
                if (M2Pin > 0) {
                    digitalWrite(M2Pin,HIGH);
                } else {
                    return false;
                }
                if (M3Pin > 0) {
                    digitalWrite(M3Pin,LOW);
                }
                return true;
                break;
            case 8:
                if (M1Pin > 0) {
                    digitalWrite(M1Pin,HIGH);
                } else{
                    return false;
                }
                if (M2Pin > 0) {
                    digitalWrite(M2Pin,HIGH);
                } else {
                    return false;
                }
                if (M3Pin > 0) {
                    digitalWrite(M3Pin,LOW);
                }
                return true;
                break;
            case 16:
                if (M1Pin > 0) {
                    digitalWrite(M1Pin,LOW);
                }
                if (M2Pin > 0) {
                    digitalWrite(M2Pin,LOW);
                } else {
                    return false;
                }
                if (M3Pin > 0) {
                    digitalWrite(M3Pin,HIGH);
                } else {
                    return false;
                }
                return true;
                break;
            case 32:
                // TODO: there could be better if loop to go through all possibilities
                // for example, M1 HIGH, M2 HIGH and M3 HIGH
                if (M1Pin > 0) {
                    digitalWrite(M1Pin,HIGH);
                } else {
                    return false;
                }
                if (M2Pin > 0) {
                    digitalWrite(M2Pin,LOW);
                } 
                if (M3Pin > 0) {
                    digitalWrite(M3Pin,HIGH);
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

bool ProjectStepControl::TogglePin(int pin_num) {
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

bool ProjectStepControl::ToggleReset() {
    return TogglePin(ResetPin);
}

bool ProjectStepControl::ToggleSleep() {
    return TogglePin(SleepPin);
}

bool ProjectStepControl::ToggleEnable() {
    return TogglePin(EnablePin);
}

// if direction is true or 1 or HIGH, clockwise direction
// if direction is false or 0 or LOW, counter clockwise direction
void ProjectStepControl::TakeStep(bool direction) {
    if (direction) {
        digitalWrite(DirPin,HIGH);
    } else {
        digitalWrite(DirPin,LOW);
    }
    // TODO: simple for loop taken from tutorial
    // needs to be better
    for (int x = 0; x < StepsPerRevolution; x++) {
        digitalWrite(StepPin,HIGH);
        delay(20);
        digitalWrite(StepPin,LOW);
    }
}

bool ProjectStepControl::SetStepsPerRevolution(int new_StepsPerRevolution) {
    if (new_StepsPerRevolution > 0) {
        StepsPerRevolution = new_StepsPerRevolution;
        return true;
    } else {
        return false;
    }
}
