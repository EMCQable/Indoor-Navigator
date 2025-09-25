
#include <Arduino.h>
#include "Blink.hpp"
#include "WifiConnection.hpp"


const int dirPin1 = 2;
const int dirPin2 = 32;
const int dirPin3 = 33;

const char* ssid = "Stadinetti";
const char* password = "";
// For some reason only works with 9600 baudrate
const short int serial_speed = 9600; 

Blink blink = Blink(dirPin1, 10);
Blink blinkb = Blink(dirPin3, 10);
ProjectWiFi projectwifi(password, ssid);

void setup() {
  Serial.begin(serial_speed);
  // wait until serial is open with USB
  while (!Serial) {
    delay(5);
  };
  Serial.println("Serial activated");

  bool ret = projectwifi.Connect_WiFi();

  pinMode(dirPin2, OUTPUT);
  digitalWrite(dirPin2, HIGH);
}

void loop() {
  blink.update();
  blinkb.update();
  if (projectwifi.is_connected()) {
    Serial.println("Connected!");
  } else { 
    Serial.println("Disconnected.");
  }
} 