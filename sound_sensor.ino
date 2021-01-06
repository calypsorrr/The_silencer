/*
    Sound Sensor

    To print the measurements made by the analog sound sensor on analog pin 0

    The circuit:
      inputs: DFRobot analog sound sensor on pin A0
      outputs: none
     
    5/01/2021
    Senne De Winter
*/

int Sensor = A0;              //to put the sound sensor on analog pin 0
int level;                    //to create a sound level integer
unsigned long var1 = 0;       //to create a first variable for using millis
unsigned long var2 = 0;       //to create a second variable for using millis

void setup() {
  Serial.begin(9600);         //to begin the serial communication at 9600 baud rate
}

void loop() {
  var1 = millis();            //to equalize var1 to millis

  if (var1 - var2 >= 5000) {  //to do something after 5 seconds
    level = analogRead(A0);   //to define level as the analog readings from the sound sensor
    Serial.println(level);    //to print the sound level
    var2 = var1;              //to equalize variable2
  } 

}
