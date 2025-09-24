
#include <Arduino.h>
#include "Blink.hpp"
#include "WifiConnection.hpp"

//Blink blink = Blink(2, 10);
//Blink blinkb = Blink(33, 10);

const char* ssid = "";
const char* password = "";
const short int serial_speed = 9600; // For some reason only works with 9600 baudrate

ProjectWiFi projectwifi(password, ssid);

void setup() {
  Serial.begin(serial_speed);
  // wait until serial is open with USB
  while (!Serial) {
    delay(5);
  };
  Serial.println("Serial activated");

  bool ret = projectwifi.Connect_WiFi();

  // Old blink code
  //blink = Blink(2, 1);
  //blinkb = Blink(33, 1);
  //pinMode(32, OUTPUT);
  //digitalWrite(32, HIGH);
}

void loop() {
  //blink.update();
  //blinkb.update();
  if (projectwifi.is_connected()) {
    Serial.println("Connected!");
  } else { 
    Serial.println("Disconnected.");
  }
  delay(2000);
} 