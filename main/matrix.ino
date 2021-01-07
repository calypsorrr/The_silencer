/*
    matrix

   First the led matrix will say that it is to loud and after 5 seconds in delay it wil say that it is ok now 

    The circuit:
    * Analog Sound Sensor SKU DFR0034
    * 

    Created 04 01 2021
    By Bo Claes
    Modified 06 01 2021
    By Bo Claes
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
  matrix.setCursor(1,0);
  matrix.setTextSize(2); 
  
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('T');
  matrix.setTextColor(matrix.Color333(7,4,0));
  matrix.print('o');
  matrix.setTextColor(matrix.Color333(7,7,0));
  matrix.print('-');
  matrix.setTextColor(matrix.Color333(4,7,0));
  matrix.print('l');
  matrix.setTextColor(matrix.Color333(0,7,0));
  matrix.print('o');
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('u');
  matrix.setTextColor(matrix.Color333(7,4,0));
  matrix.print('d');

  delay(5000);

  matrix.setCursor(1,9);
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('I');
  matrix.setTextColor(matrix.Color333(7,4,0));
  matrix.print('t');
  matrix.setTextColor(matrix.Color333(7,7,0));
  matrix.print('-');
  matrix.setTextColor(matrix.Color333(4,7,0));
  matrix.print('i');
  matrix.setTextColor(matrix.Color333(0,7,0));
  matrix.print('s');
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('-');
  matrix.setTextColor(matrix.Color333(7,4,0));
  matrix.print('o');
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print('k');
  matrix.setTextColor(matrix.Color333(7,4,0));
  matrix.print('-');
  matrix.setTextColor(matrix.Color333(7,7,0));
  matrix.print('n');
  matrix.setTextColor(matrix.Color333(4,7,0));
  matrix.print('o');
  matrix.setTextColor(matrix.Color333(0,7,0));
  matrix.print('w');
}
