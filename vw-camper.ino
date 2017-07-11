#include <Time.h>
#include <TimeLib.h>

int sensor = A0;         // Sensor is connected on analogue pin 0
int sensorValue;         // Where sensor value is stored
int lights = 3;          // Pin that the lighting system is connected to
int minDayLevel = 900;   // Min light level for day
int minNightLevel = 200; // Min light level for night
int pollDelay = 1800000; // ms between checking the light level

void setup() {
}

void loop() {
  if (hour() >= 18 && hour() < 22) { // It's currently within hours of operation (18:00 - 22:00)
    sensorValue = analogRead(sensor);
    if (sensorValue > minNightLevel && sensorValue < minDayLevel) { // Light level is within the disired range
      lightsOn(sensorValue / 8); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
      delay(pollDelay);
      return;
    }
  }
  lightsOff();
  delay(pollDelay);
}

void lightsOn(int level) {
  digitalWrite(LED_BUILTIN, HIGH);
  analogWrite(lights, level);
}

void lightsOff() {
  digitalWrite(LED_BUILTIN, LOW);
  analogWrite(lights, 0);
}

