# Indoor-Navigator
Robot that navigates indoors and manipulates the environment and communicates through server

# Components
- ESP32-WROOM-32D development board
- 2 x Haboise 17HS3430 step motors 
- 2 x DRV8825 step motor driver circuit

# CHEAT SHEET: Compiling with arduino-cli
## List of Available boards
```
arduino-cli board list
```
## Compile sketch 
```
arduino-cli compile --fqbn esp32:esp32:esp32doit-devkit-v1 .
```
## Upload the sketch
```
arduino-cli upload -p /dev/BOARD_HERE --fqbn esp32:esp32:esp32doit-devkit-v1 . 
```
## Open monitor 
```
arduino-cli monitor -p /dev/BOARD_HERE -b esp32:esp32:esp32doit-devkit-v1 --config 9600
```
