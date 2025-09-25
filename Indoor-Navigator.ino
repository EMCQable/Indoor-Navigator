#include <Arduino.h>
#include "WifiConnection.hpp"
#include "DRV8825Controller.hpp"

const int dirPin1 = 2;
const int dirPin2 = 32;
const int dirPin3 = 33;

const char* ssid = "";
const char* password = "";
// For some reason only works with 9600 baudrate
const short int serial_speed = 9600; 

ProjectWiFi projectwifi(password, ssid);

ProjectStepControl stepper(1,0,0,0,0,0,(int) dirPin2,0, (int) dirPin3);

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
} 