/*
    Sketch_LedMatrix

    For 32x16 RGB LED matrix.

    The circuit:
      Input:
       SoundSensor
      Output
       Led

    Created 8/01/2021
    By Myrthe Diepeveen

    Modified 8/01/2021
    By Myrthe Diepeveen
*/

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

void setup() {
  matrix.begin();

}

void loop() {
  matrix.setCursor(1, 0);   // start at top left, with one pixel of spacing
  matrix.setTextSize(1);    // size 1 == 8 pixels high

  // print each letter in red
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('Q');
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('U');
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('I');
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('E');
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('T');

}
