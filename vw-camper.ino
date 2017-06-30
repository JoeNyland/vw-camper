#include <Time.h>
#include <TimeLib.h>

int sensor = A0;         // Sensor is connected on analogue pin 0
int sensorValue;         // Where sensor value is stored
int lights = 2;          // Lighting system is connected to digital output pin 2
int maxDayLevel = 600;   // Max light level for day
int minNightLevel = 200; // Min light level for night

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(lights, OUTPUT);
}

void loop() {
  if (hour() >= 18) { // It's currently within hours of operation
    sensorValue = analogRead(sensor);
    if (sensorValue > minNightLevel && sensorValue < maxDayLevel) { // Light level is within the disired range
      lightsOn();
      delay(1000);
      return;
    }
  }
  lightsOff();
  delay(1000);
  return;
}

void lightsOn() {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(lights, HIGH);
}

void lightsOff() {
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(lights, LOW); 
}

