/*
    Sketch_GELUIDSSENSOR

    To measure when there is a sound detected by the analog soundsensor. 
    To print out the measurments and turn the led on when there is a sound.

    The circuit:
      Input: SoundSensor
      Output: Led

    Created 5/01/2021
    By Myrthe Diepeveen
    
    Modified 6/01/2021
    By Myrthe Diepeveen
*/

int soundSensor = A0;                                  //To put the soundsensor on analog pin 0
int LED = 12;                                          //To put the led on pin 12
int threshold = 200;

void setup() {
  pinMode (LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor_value = analogRead(soundSensor);            //To set the sensor to analog
  Serial.println (sensor_value);                         //To print out the measurments
  if (sensor_value > threshold) {
    digitalWrite (LED, HIGH);                            //Turn LED on
  }
  else digitalWrite (LED, LOW); {                        //Turn LED off
  }
}
