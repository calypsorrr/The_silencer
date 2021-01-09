/*
    The Silencer

    To print a reading from the Aanalog sound sensor
    onto the led matrix that's connected to pins:
    8, A3, 9, A0, A1 and A2

    The circuit:
      inputs: Analog sound sensor on pin A4
      outputs: led matrix on pins 8,9, A0, A1, A2, A3

    9/01/2021
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

int Sensor = A4;              //to put the sound sensor on analog pin 4
int level;                    //to create a sound level integer
unsigned long var1 = 0;       //to create a first variable for using millis
unsigned long var2 = 0;       //to create a second variable for using millis


void setup() {
  matrix.begin();                //to begin the matrix
}

void loop() {
  var1 = millis();            //to equalize var1 to millis
  if (var1 - var2 >= 5000) {  //to do something after 5 seconds
    readSensor();             //to execute the readSensor function
    printMatrix();            //to execute the printMatrix function
    var2 = var1;              //to equalize variable2 to variable1
  } 
}

void readSensor(){
  level = analogRead(A0);   //to define level as the analog readings from the sound sensor
}

void printMatrix(){
  if (level < 341){                             //to do something if the level is < 341
    matrix.fillScreen(matrix.Color333(0,0,0));  //to make the matrix black
  }
  if (level > 342 && level < 683){              //to do something if 342< level < 683
    matrix.fillScreen(matrix.Color333(0,7,0));  //to make the matrix green
  }
  if (level > 683){                             //to do something if the level is > 683
    matrix.fillScreen(matrix.Color333(7,0,0));  // to make the matrix red
  } 
}
