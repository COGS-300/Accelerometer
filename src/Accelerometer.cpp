#include <Arduino.h>
#include "Accelerometer.h"

/**
 * @brief Construct a new Accelerometer object.
 */
Accelerometer::Accelerometer()
{
}

/**
 * @brief Initialize the accelerometer (MPU6050) and establish I2C communication.
 */
void Accelerometer::begin()
{
    Wire.begin();     // Initialize I2C communication
    mpu.initialize(); // Initialize MPU6050 sensor

    Serial.println("Testing MPU6050 connection...");
    if (!mpu.testConnection())
    {
        Serial.println("MPU6050 connection failed!");
        while (1)
            ; // Halt execution if connection fails
    }
    Serial.println("MPU6050 connected successfully!");
}

/**
 * @brief Reads accelerometer and gyroscope values from the MPU6050 sensor.
 *        Calculates roll and pitch angles.
 */
void Accelerometer::read()
{
    // Read raw acceleration and gyroscope data
    mpu.getAcceleration(&ax, &ay, &az);
    mpu.getRotation(&gx, &gy, &gz);

    acc_x = float(ax);
    acc_y = float(ay);
    acc_z = float(az);

    gyro_x = float(gx);
    gyro_y = float(gy);
    gyro_z = float(gz);

    // Compute roll and pitch angles in degrees
    roll = atan2(acc_y, acc_z) * 180.0 / PI;
    pitch = atan2((-acc_x), sqrt(acc_y * acc_y + acc_z * acc_z)) * 180.0 / PI;
}

/**
 * @brief Prints raw accelerometer and gyroscope values to the Serial Monitor.
 */
void Accelerometer::print()
{
    char buffer[50];
    sprintf(buffer, "Accl (x, y, z): %7lf %7lf %7lf", acc_x, acc_y, acc_z);
    Serial.println(buffer);
    sprintf(buffer, "Gyro (x, y, z): %7lf %7lf %7lf", gyro_x, gyro_y, gyro_z);
    Serial.println(buffer);
}

/**
 * @brief Sends computed roll and pitch angles as a JSON-formatted string via Serial communication.
 */
void Accelerometer::send_tilts()
{
    char buffer[150];
    sprintf(buffer, "{\"name\":\"tilt\", \"roll\": %f, \"pitch\": %f}", roll, pitch);
    Serial.println(buffer);
}

/**
 * @brief Sends raw accelerometer and gyroscope values as a JSON-formatted string via Serial communication.
 */
void Accelerometer::send_raw()
{
    char buffer[150];
    sprintf(buffer, "{\"name\":\"accelerometer_raw\", \"ax\": %d, \"ay\": %d, \"az\": %d, \"gx\": %d, \"gy\": %d, \"gz\": %d}", ax, ay, az, gx, gy, gz);
    Serial.println(buffer);
}
