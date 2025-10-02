#include <Arduino.h>
#include "WifiConnection.hpp"
#include "DRV8825Controller.hpp"

// DO NOT USE PORTS 34-36,39 PORTS FOR OUTPUT
constexpr int dirPin = 32;
constexpr int stepPin = 33;

const char* ssid = "Stadinetti";
const char* password = "";
// For some reason only works with 9600 baudrate
const short int serial_speed = 9600; 

ProjectWiFi projectwifi(password, ssid);

ProjectStepControl stepper(1,0,0,0,0,0,stepPin,0,dirPin);

void setup() {
  Serial.begin(serial_speed);
  // wait until serial is open with USB
  while (!Serial) {
    delay(5);
  };
  Serial.println("Serial activated");

  bool ret = projectwifi.Connect_WiFi();
}

void loop() {
  // take a step

  if (projectwifi.is_connected()) {
    Serial.println("Connected!");
  } else { 
    Serial.println("Disconnected.");
  }
  stepper.TakeStep(false);
} 