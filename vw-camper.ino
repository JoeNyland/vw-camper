#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

int sensor = A0;         // Sensor is connected on analogue pin 0
int sensorValue;         // Where sensor value is stored
int lights = 3;          // Pin that the lighting system is connected to
int minDayLevel = 900;   // Min light level for day
int minNightLevel = 200; // Min light level for night
int pollDelay = 1800000; // ms between checking the light level

void setup() {
  Serial.begin(9600);
  rtc.begin();
}

void loop() {
  DateTime now = rtc.now();

  // {rint current sensor value
  Serial.print("Sensor value: ");
  Serial.println(analogRead(sensor));

  // Print current time
  Serial.print("Time: ");
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  if (now.hour() >= 18 && now.hour() < 22) { // It's currently within hours of operation (18:00 - 22:00)
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

