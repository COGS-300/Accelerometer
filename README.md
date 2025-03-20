# Accelerometer Library for MPU6050

## Overview
This library provides an easy-to-use interface for working with the MPU6050 accelerometer and gyroscope sensor using an Arduino. It enables reading raw accelerometer and gyroscope data, computing roll and pitch angles, and sending data via serial communication in JSON format.

## Features
- Initialize and configure the MPU6050 sensor
- Read accelerometer (X, Y, Z) and gyroscope (X, Y, Z) data
- Compute roll and pitch angles
- Print sensor data to Serial Monitor
- Send raw and computed sensor data as JSON

## Requirements
- Arduino board (e.g., Arduino Uno, Mega, Nano)
- MPU6050 sensor module
- Arduino IDE
- `Wire.h` library (for I2C communication)
- `MPU6050.h` library (for sensor control)

## Installation
1. Clone this repository or download the source files.
2. Add the library to your Arduino libraries folder.
3. Ensure you have the `MPU6050` library installed via the Arduino Library Manager.

## Usage
### 1. Include the Library
```cpp
#include <Arduino.h>
#include "Accelerometer.h"
```

### 2. Initialize the Sensor
```cpp
Accelerometer accel;

void setup() {
    Serial.begin(115200);
    accel.begin();
}
```

### 3. Read and Print Data
```cpp
void loop() {
    accel.read();
    accel.print();
    delay(1000); // Wait 1 second before next read
}
```

### 4. Send Data as JSON
```cpp
void loop() {
    accel.read();
    accel.send_raw();
    accel.send_tilts();
    delay(1000);
}
```

## JSON Output Format
### Raw Data
```json
{
    "name": "accelerometer_raw",
    "ax": 123,
    "ay": 456,
    "az": 789,
    "gx": 10,
    "gy": 20,
    "gz": 30
}
```

### Tilt Data
```json
{
    "name": "tilt",
    "roll": 12.34,
    "pitch": -45.67
}
```

## Notes
- The roll and pitch calculations use basic trigonometry and may require calibration for better accuracy.
- You can modify the `Accelerometer` class to include offset calibration.

## License
This project is licensed under the MIT License.

## Author
**Paul Bucci**  
Created on March 19, 2025

