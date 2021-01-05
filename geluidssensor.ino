#include <Chrono.h>


int sensor_value = 0;
int threshold = 100;
int abs_value = 0;
int led = 12;
Chrono chronoA;

void setup() {
  Serial.begin(9600); // setup serial
  pinMode(led, OUTPUT);
}

void loop() {
  sensor_value = analogRead(A0);
   if (threshold < sensor_value){
      digitalWrite(led, HIGH);
      chronoA.restart();
   }
   else if(chronoA.hasPassed(5000)){
    digitalWrite(led, LOW);
      chronoA.stop();
   }
    Serial.println(sensor_value);
}
