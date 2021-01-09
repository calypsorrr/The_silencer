/*
    Matrix Test

    To print a message onto the led matrix that's connected to pins:
    8, A3, 9, A0, A1 and A2

    The circuit:
      inputs: none
      outputs: led matrix on pins 8,9, A0, A1, A2, A3

    6/01/2021
    Senne De Winter
*/

#include <Adafruit_GFX.h>        //to use the Adafruit GFX library
#include <RGBmatrixPanel.h>      //to use the RGBmatrixPanel library

#define CLK 8                    //to attach CLK to digital pin 8
#define LAT A3                   //to attach LAT to analog pin 3
#define OE  9                    //to attach OE to digital pin 9
#define A   A0                   //to attach A to analog pin 0
#define B   A1                   //to attach B to analog pin 1
#define C   A2                   //to attach B to analog pin 2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);   //to make the RGB matrix a matrix using A,B,C,CLK,LAT and OE

void setup() {
  matrix.begin();                //to begin the matrix
}

void loop() {
  matrix.setCursor(1, 0);                        //to set the cursor on line 1
  matrix.setTextSize(1);                         //to set the text size to 1
  matrix.setTextColor(matrix.Color333(7, 7, 7)); //to set the text color to white
  matrix.print("KdG The Silencer");              //to print text on the RGB matrix
}
