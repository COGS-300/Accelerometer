#include <Accelerometer.h>
#include "config.h"

Accelerometer accelerometer;

void setup() {
  Serial.begin(ROBOT_BAUD_RATE);
  accelerometer.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  accelerometer.read();
  accelerometer.send_raw();
  accelerometer.send_tilts();

  delay(1000);
}
