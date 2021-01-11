/*
    The Silencer
    We use a sound sensor to determine if it is to loud. If it is to loud a led light will light up. When the noise is down the led will stay on for 5 more seconds.
    The circuit:
      Input:
      Gravity: Analog Sound Sensor For Arduino on analog pin A0
      Output:
      LED light on pin 12
    Created 06/01/2021
    By Stijn Janssen
    Modified 06/01/2021
    By Stijn Janssen
*/

#include <Chrono.h>

int sensor_value = 0;
int threshold = 100;
int abs_value = 0;
int led = 12;
Chrono chronoA;
Chrono chronoB;

void setup() {
  Serial.begin(9600); // setup serial
  pinMode(led, OUTPUT);
}

void loop() {
  sensor_value = analogRead(A0);
  if (threshold < sensor_value) {
    digitalWrite(led, HIGH);
    chronoA.restart();
  }
  else if (chronoA.hasPassed(5000)) {
    digitalWrite(led, LOW);
    chronoA.stop();
  }
  if (chronoB.hasPassed(100) || threshold < sensor_value) {
    chronoB.restart();
    Serial.println(sensor_value);
  }
}
