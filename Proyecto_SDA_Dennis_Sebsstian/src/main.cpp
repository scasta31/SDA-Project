#include <Arduino.h>
#include <sensors/sensor.h>
#include <llp.h>
#include <time.h>

uint8_t sensor_input = 33;
Sensor<int> sensor = Sensor<int>(0xA0, sensor_input);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.execute();
  if (sensor.hasChanged() ){
    DataPack input = DataPack();
    input.addData(sensor.getId(), sensor.getValue());
    input.write(Serial);
    sleep(10);
  }
}