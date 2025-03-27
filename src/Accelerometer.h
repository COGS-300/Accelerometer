/**
 * Accelerometer.h - Library for interfacing with MPU6050 Accelerometer
 * Created by Paul Bucci, March 19, 2025
 */

#ifndef Accelerometer_h
#define Accelerometer_h

#include <Arduino.h>
#include <Wire.h>
#include <MPU6050.h>

/**
 * @brief Class to interface with the MPU6050 accelerometer and gyroscope.
 */
class Accelerometer
{

private:
    int16_t ax, ay, az; ///< Raw accelerometer data (X, Y, Z)
    int16_t gx, gy, gz; ///< Raw gyroscope data (X, Y, Z)

    int16_t ax_offset, ay_offset, az_offset; ///< Accelerometer calibration offsets
    int16_t gx_offset, gy_offset, gz_offset; ///< Gyroscope calibration offsets

public:
    float acc_x, acc_y, acc_z;
    float gyro_x, gyro_y, gyro_z;

    MPU6050 mpu; // MPU6050 sensor object

    float roll, pitch; ///< Computed roll and pitch angles

    /**
     * @brief Construct a new Accelerometer object.
     */
    Accelerometer();

    /**
     * @brief Initializes the MPU6050 sensor and establishes I2C communication.
     */
    void begin();

    /**
     * @brief Reads raw acceleration and gyroscope values from the MPU6050.
     *        Computes roll and pitch angles based on acceleration data.
     */
    void read();

    /**
     * @brief Prints raw accelerometer and gyroscope data to the Serial Monitor.
     */
    void print();

    /**
     * @brief Sends raw sensor data as a JSON-formatted string via Serial communication.
     */
    void send_raw();

    /**
     * @brief Sends computed tilt (roll and pitch) values as a JSON-formatted string via Serial communication.
     */
    void send_tilts();
};

#endif
