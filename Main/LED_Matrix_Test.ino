/*
    Sound Sensor testing

    Program to test the sound sensor that we will be using for our project.

    The circuit:
    * Sound sensor

    Created 06 January 2021
    By Tibo Smet
    Modified 08 January 2021
    By Tibo Smet
*/

int soundSensor = analogRead(0);           // Connect sound sensor to Analog pin 0

void setup() {
  Serial.begin(9600);                      // Starts Serial monitor
}

void loop() {
  Serial.println(soundSensor, DEC);        //print the sound value to serial
  delay(100);
}
