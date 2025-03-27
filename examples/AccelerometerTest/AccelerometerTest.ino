#include <Accelerometer.h>       // Include the Accelerometer library for reading sensor data
#include "config.h"              // Include configuration file for constants like ROBOT_BAUD_RATE

Accelerometer accelerometer;     // Create an instance of the Accelerometer class

void setup() {
  Serial.begin(ROBOT_BAUD_RATE); // Initialize serial communication at the baud rate defined in config.h
  accelerometer.begin();         // Initialize the accelerometer sensor
}

void loop() {
  accelerometer.read();          // Read data from the accelerometer
  accelerometer.send_raw();      // Send raw accelerometer readings over serial
  accelerometer.send_tilts();    // Send tilt information (e.g., pitch, roll) over serial
  delay(1000);                   // Wait for 1 second before the next reading
}
