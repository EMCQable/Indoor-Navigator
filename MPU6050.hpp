#pragma once

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>

#define LED_BUILTIN 2

class MPU6050 {
    public:
        MPU6050();
        void initialize();
        void update();

    private:
        Adafruit_MPU6050 mpu_;
};