# Indoor-Navigator
Robot that navigates indoors and manipulates the environment


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
arduino-cli monitor -p /dev/BOARD_HERE -b esp32:esp32:esp32doit-devkit-v1
```