
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);

  // Start the MPU6050
  if (!mpu.begin()) {
    Serial.println("MPU6050 NOT FOUND!");
    Serial.println("Check your wiring nigga");
    
    while (1) {
      delay(10);
    }
  }

//Serial.println("MPU6050 FOUND!");
//Serial.println("Reading sensor...");
//Serial.println();

  // Accelerometer range
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // Gyroscope range
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // Filter
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
//Serial.println("HELLO FROM ARDUINO");

  sensors_event_t acceleration;
  sensors_event_t gyro;
  sensors_event_t temperature;

  mpu.getEvent(&acceleration, &gyro, &temperature);

  float z = acceleration.acceleration.z;
  float x = acceleration.acceleration.x;
  float y = acceleration.acceleration.y;

  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.println(z);



// command pio device monitor -p /dev/ttyACM0 -b 115200 (to show values)


  delay(200);
}

