#pragma once

class Motor {
   public:
    Motor(const int motorPin, int freq, int resolution, int channel);
    Motor(const int motorPin, int channel);
    ~Motor();
    void setSpeed(char newSpeed);

   private:
    int motorPin_;
    int channel_;
    unsigned long previousMillis_;
    bool ledState_;
};