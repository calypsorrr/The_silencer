/*
    LED Matrix testing

    Program to test the LED Matrix that we will be using for our project.

    The circuit:
    * LED Matrix

    Created 06 January 2021
    By Tibo Smet
    Modified 06 January 2021
    By Tibo Smet
*/

#include <Adafruit_GFX.h>             // Core graphics library
#include <RGBmatrixPanel.h>           // Library for the LED-Matrix

#define CLK 8
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
  matrix.fillScreen(matrix.Color333(7, 0, 0));      // Turns the matrix Red
  delay(100);
  
  matrix.fillScreen(matrix.Color333(0, 7, 0));      // Turns the matrix Green
  delay(100);
  
  matrix.fillScreen(matrix.Color333(0, 0, 7));      // Turns the matrix Blue
  delay(100);
  
  matrix.fillScreen(matrix.Color333(7, 7, 0));      // Turns the matrix Yellow
  delay(100);

  matrix.fillScreen(matrix.Color333(7, 0, 7));      // Turns the matrix Purple
  delay(100);
    
  matrix.fillScreen(matrix.Color333(7, 7, 7));      // Turns the matrix white
  delay(100);
  
  matrix.fillScreen(matrix.Color333(0, 0, 0));      // Turns the matrix Black
  delay(100);
}
