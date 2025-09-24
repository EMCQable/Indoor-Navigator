#include "WifiConnection.hpp"
#include <WiFi.h>

ProjectWiFi::ProjectWiFi(const char* password, const char* ssid) {
    this->ssid = ssid;
    this->password = password;
}

ProjectWiFi::~ProjectWiFi() {
}

bool ProjectWiFi::Connect_WiFi() {
    Serial.println("Connecting to WiFi");
    WiFi.begin(ssid, password);

    int retry = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        if (retry++ > 10) {
            Serial.println("\nFailed to connect to WiFi.");
            return false;
        }
    }

    Serial.println("\nWiFi connected.");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    return true;
}

bool ProjectWiFi::is_connected() {
    if (WiFi.status() == WL_CONNECTED) {
        return true;
    } else {
        return false;
    }
}