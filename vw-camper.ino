#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

int sensor = A0;         // Sensor is connected on analogue pin 0
int sensorValue;         // Where sensor value is stored
int lights = 3;          // Pin that the lighting system is connected to
int minDayLevel = 900;   // Min light level for day
int pollDelay = 1000;    // ms between checking the light level

void setup() {
  rtc.begin();
}

void loop() {
  DateTime now = rtc.now();
  if (now.hour() >= 18 && now.hour() < 22) { // It's currently within hours of operation (18:00 - 22:00)
    sensorValue = analogRead(sensor);
    if (sensorValue < minDayLevel) { // Light level is within the desired range
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

