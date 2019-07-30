#include <Wire.h>
#include <RTClib.h>

int sensorPin = A0;
int lightsPin = 3;
int ambientLightThreshold = 200;
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power; setting the time");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);

  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print("T");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print(" Sensor:");
  Serial.print(sensorVal);
  Serial.println();

  bool output = now.hour() >= 18 && now.hour() < 22 && sensorVal < ambientLightThreshold;
  digitalWrite(LED_BUILTIN, output);
  digitalWrite(lightsPin, output);
}
