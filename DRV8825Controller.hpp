#pragma once
#include "Motor.hpp"

class DRV8825Controller {
    /*
     * A class controlling DRV8825 Controller Circuit
     */
   public:
    DRV8825Controller(char stepResolution, char resolutionPin1, char resolutionPin2,
                      char resolutionPin3, char resetPin, char sleepPin, char motorPin,
                      char enablePin, char dirPin, char pwmChannel);
    bool setStepsPerRevolution(int new_StepsPerRevolution);
    bool setStepResolution(unsigned int resolution);
    bool toggleReset();
    bool toggleSleep();
    bool toggleEnable();
    void setSpeed(bool direction, char motorSpeed);

   private:
    Motor motor_;

    bool togglePin(int pin_number);

    // TODO: the memory consumption could be cut by choosing
    // smaller types than int
    int stepResolution_;
    int turnRate_;

    // Pins
    const char motorPin_;
    const char dirPin_;
    const unsigned char resolutionPin1_;
    const unsigned char resolutionPin2_;
    const unsigned char resolutionPin3_;
    const char enablePin_;
    const char resetPin_;
    const char sleepPin_;
};