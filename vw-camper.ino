#include <Time.h>
#include <TimeLib.h>

int sensor = A0;         // Sensor is connected on analogue pin 0
int sensorValue;         // Where sensor value is stored
int lights = 3;          // Pin that the lighting system is connected to
int maxDayLevel = 600;   // Max light level for day
int minNightLevel = 200; // Min light level for night

void setup() {
}

void loop() {
  if (hour() >= 18) { // It's currently within hours of operation
    sensorValue = analogRead(sensor);
    if (sensorValue > minNightLevel && sensorValue < maxDayLevel) { // Light level is within the disired range
      lightsOn(sensorValue / 8); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
      delay(10);
      return;
    }
  }
  lightsOff();
  delay(10);
  return;
}

void lightsOn(int level) {
  analogWrite(LED_BUILTIN, level);
  analogWrite(lights, level);
}

void lightsOff() {
  analogWrite(LED_BUILTIN, 0);
  analogWrite(lights, 0);
}

