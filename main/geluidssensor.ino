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
    Modified 13/01/2021
    By Stijn Janssen
*/

#include <Chrono.h>
#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>

#define CLK 8
#define LAT A3
#define OE 9
#define A A0
#define B A1
#define C A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

int sensor_value = 0;
int threshold = 100;
int abs_value = 0;
Chrono chronoA;
Chrono chronoB;
Chrono chronoC;

void setup() {
  Serial.begin(9600); // setup serial
  matrix.begin();
}

void loop() {
  sensor_value = analogRead(A4);
  if (threshold < sensor_value) {
    matrix.fillScreen(matrix.Color333(7, 0, 0));
    chronoA.restart();
  }
  else if (chronoA.hasPassed(5000)) {
    matrix.fillScreen(matrix.Color333(0, 7, 0));
    chronoA.stop();
  }
  if (chronoC.hasPassed(1000) && threshold < sensor_value){
    Serial.println(sensor_value);
    chronoC.restart();
  }
  else if (chronoB.hasPassed(2000) && threshold > sensor_value){
    chronoB.restart();
    Serial.println(sensor_value);
  }
}
