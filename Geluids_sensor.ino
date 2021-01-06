/*
    Geluids_Sensor

   The RGB on pin 10 will go on green if it is in normal decibel range, 
   it will go yellow on pin 11 if it is above 100 and red on pin 12 when it is above 200 

    The circuit:
    * Analog Sound Sensor SKU DFR0034
    * 1 RGB led

    Created 04 01 2021
    By Bo Claes
    Modified 06 01 2021
    By Bo Claes
*/

#include <Chrono.h>

// The diffrent ports for the RGB and the sensor
int RGB_Green = 10;                                           
int RGB_Yellow = 11;
int RGB_Red = 12;
int Sound_Sensor_Pin = A0;                               

int Sensor_Value = 0;                                     // The value of the sensor begins at 0
int RED_Value = 200;                                      // I set the maximum value of the sensor on 200 and make the RGB red
int YELLOW_Value = 100;                                   // I set the maximum value of the sensor on 100 and make the RGB yellow

// The values for the different collors 
int Red_Val = (255,0,0);                                  
int Yellow_Val = (255,255,0);
int Green_Val = (0,255,0);

// The different chrono's
Chrono chronoA;
Chrono chronoB;
Chrono chronoC;

void setup() {
  // I inizialise the serial monitor and the output
  // I set the RGB collor green on in the beginning 
  Serial.begin(9600);
  pinMode(RGB_Green, OUTPUT);
  pinMode(RGB_Yellow, OUTPUT);
  pinMode(RGB_Red, OUTPUT);
  digitalWrite(RGB_Green, HIGH);
  analogWrite (RGB_Green, Green_Val);
}

void loop() {
  // I set the sensor to analog
  Sensor_Value = analogRead(Sound_Sensor_Pin);
  // When the value of (Sensor_value) is bigger then (YELLOW_Value), the green led will go of and the yellow wil go on
  if (YELLOW_Value < Sensor_Value) {
    digitalWrite(RGB_Green, LOW);
    digitalWrite(RGB_Yellow, HIGH);
    analogWrite(RGB_Yellow, Yellow_Val);
    chronoA.restart();
  }
  // After 5 seconds the yellow light will go off and the green wil be back up
  else if(chronoA.hasPassed(5000)) {
    digitalWrite(RGB_Yellow, LOW);
    chronoA.stop();
    digitalWrite(RGB_Green, HIGH);
  }
  // When the value of (Sensor_value) is bigger then (RED_Value), the green and the yellow led will go of and the red wil go on
  if (RED_Value < Sensor_Value) {
    digitalWrite(RGB_Green, LOW);
    digitalWrite(RGB_Yellow, LOW);
    digitalWrite(RGB_Red, HIGH);
    analogWrite(RGB_Red, Red_Val);
  }
  // After 5 seconds the red light will go off and the green wil be back up
  else if (chronoB.hasPassed(5000)) {
    digitalWrite(RGB_Red, LOW);
    chronoB.stop();
    digitalWrite(RGB_Green, HIGH);
  }
  // This will just speed down the plotter and the monitor
  if (chronoC.hasPassed(100)) {
    Serial.print(Sensor_Value);
    chronoB.restart();
  }
  else {
    chronoC.stop();
  }
}
