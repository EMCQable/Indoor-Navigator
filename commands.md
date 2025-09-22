# Commands for ESP32

## Install
arduino-cli config init
arduino-cli config set network.timeout 600
arduino-cli core update-index
arduino-cli core install esp32:esp32

### Check
arduino-cli core list
arduino-cli board list
arduino-cli board listall esp32

## Compile and upload EPS32
arduino-cli compile --fqbn esp32:esp32:esp32
arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32

## Compile and upload Arduino Nano
arduino-cli compile --fqbn arduino:avr:nano:cpu=atmega328old
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:nano:cpu=atmega328old