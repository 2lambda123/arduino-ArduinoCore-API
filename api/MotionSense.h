/*
  MotionSense API
  Copyright (c) 2016 Arduino LLC. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef ARDUINO_MOTION_SENSE_H
#define ARDUINO_MOTION_SENSE_H

// Base class for gyroscope
class Gyroscope {
  // Read a gyro sample from the FIFO or wait until one is available.
  // Results are in degrees/second.
  virtual bool readGyroscope(float &x, float &y, float &z) = 0;

  // Number of samples in the FIFO.
  // Sensors without a FIFO should return 1 only if the sensor has
  // produced a new measurement since the most recent read.
  virtual unsigned int availableGyroscope() = 0;

  // Sampling rate of the sensor.
  virtual unsigned long sampleRateGyroscope() = 0;
};

// Base class for accelerometers
// Sensors without a FIFO can use the default implementation of
// availableXxx() and sampleRateXxx() and always return the last
// valid measurement.
class Accelerometer {
  // Read an acceleration sample from the FIFO or wait until one is available.
  // Results are in G (earth gravity).
  virtual bool readAcceleration(float &x, float &y, float &z) = 0;

  // Number of samples in the FIFO.
  virtual unsigned int availableAcceleration()   { return 1; }

  // Sampling rate of the sensor.
  virtual unsigned long sampleRateAcceleration() { return 0; }
};

// Base class for magnetometers
// Sensors without a FIFO can use the default implementation of
// availableXxx() and sampleRateXxx() and always return the last
// valid measurement.
class Magnetometer {
  // Read a magnetometer sample from the FIFO or wait until one is available.
  // Results are in uT (micro Tesla).
  virtual bool readMagneticField(float &x, float &y, float &z) = 0;

  // Returns the expected field strength. Filter algorithms can use this value
  // to detect and ignore when a strong magnetic field or nearby ferrous metal
  // objects interfere with the magnetometer readings.
  // Defaults to 50.0 uT for sensors that lacks this calibration info.
  virtual float expectedMagneticFieldStrength()   { return 50.0f; }

  // Number of samples in the FIFO.
  virtual unsigned int availableMagneticField()   { return 1; }

  // Sampling rate of the sensor.
  virtual unsigned long sampleRateMagneticField() { return 0; }
};

// EulerAngles represents a rotation in the most commonly accepted
// NED (North, East, Down) right hand rule, with:
//   yaw   from    0 to 360 degrees
//   pitch from  -90 to  90 degrees
//   roll  from -180 to 180 degrees
struct EulerAngles {
  float yaw;
  float pitch;
  float roll;
};

struct Quaternion {
  union {
    float q[4];
    struct {
      float w;
      float x;
      float y;
      float z;
    };
  };
};

#endif