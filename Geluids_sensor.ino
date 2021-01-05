#include <Chrono.h>

int Sound_Sensor_Pin = A0;                                // Sensor on A0
int Sensor_Value = 0;                                     // The value of the sensor begins at 0
int RED_Value = 200;                                      // I set the maximum value of the sensor on 200 and make the RGB red
int YELLOW_Value = 100;
int Red_Val = (255,0,0);
int Yellow_Val = (255,255,0);
int Green_Val = (0,255,0);
int RGB_Green = 10;                                           
int RGB_Yellow = 11;
int RGB_Red = 12;
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
  // 
  Sensor_Value = analogRead(Sound_Sensor_Pin);
  if (YELLOW_Value < Sensor_Value){
    digitalWrite(RGB_Green, LOW);
    digitalWrite(RGB_Yellow, HIGH);
    analogWrite(RGB_Yellow, Yellow_Val);
    chronoA.restart();
  }
  else if(chronoA.hasPassed(5000)){
    digitalWrite(RGB_Yellow, LOW);
    chronoA.stop();
    digitalWrite(RGB_Green, HIGH);
  }
  if (RED_Value < Sensor_Value){
    digitalWrite(RGB_Yellow, LOW);
    digitalWrite(RGB_Red, HIGH);
    analogWrite(RGB_Red, Red_Val);
  }
  else if (chronoB.hasPassed(5000)){
    digitalWrite(RGB_Red, LOW);
    chronoB.stop();
    digitalWrite(RGB_Green, HIGH);
  }
  if (chronoC.hasPassed(100)){
    Serial.print(Sensor_Value);
    chronoB.restart();
  }
  else{
    chronoC.stop();
  }
}
