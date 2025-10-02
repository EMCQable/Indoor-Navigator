#include "MPU6050.hpp"


MPU6050::MPU6050() {
    
}

void MPU6050::initialize() {
      if (!mpu_.begin()) {
        Serial.println("Failed to find MPU6050 chip");
        pinMode(LED_BUILTIN, OUTPUT);
        while (1) {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(10);
            digitalWrite(LED_BUILTIN, LOW);
            delay(10);
        }
      }
}

void MPU6050::update() {
    sensors_event_t a, g, temp;
  
    // Get the sensor data
    mpu_.getEvent(&a, &g, &temp);
    
    // Print accelerometer data (X, Y, Z)
    //Serial.print("Accel X: "); Serial.print(a.acceleration.x); Serial.print(" m/s^2 ");
    //Serial.print("Accel Y: "); Serial.print(a.acceleration.y); Serial.print(" m/s^2 ");
    //Serial.print("Accel Z: "); Serial.print(a.acceleration.z); Serial.println(" m/s^2 ");
    
    // Optionally, you can print the gyroscope and temperature data
    //Serial.print("Gyro X: "); Serial.print(g.gyro.x); Serial.print(" rad/s ");
    //Serial.print("Gyro Y: "); Serial.print(g.gyro.y); Serial.print(" rad/s ");
    //Serial.print("Gyro Z: "); Serial.print(g.gyro.z); Serial.println(" rad/s ");
    
    //Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" °C");
    
    //Serial.print("Gyro XYZ: ");
    //Serial.print(g.gyro.x);
    //Serial.print(", ");
    //Serial.print(g.gyro.y);
    //Serial.print(", ");
    //Serial.println(g.gyro.z);

    Serial.print("Accel XYZ: ");
    Serial.print(g.acceleration.x);
    Serial.print(", ");
    Serial.print(g.acceleration.y);
    Serial.print(", ");
    Serial.println(g.acceleration.z);
    

}