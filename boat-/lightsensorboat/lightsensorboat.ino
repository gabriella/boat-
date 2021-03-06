/*
  Analog input, analog output, serial output
 
 This code corresponds to a boat with two light sensors on either side, allowing it to
 follow the light (it steers towards the light)
 
 for how to build the boat, see levinegabriella.com/teaching
 
 //you will have to calibrate the values corresponding to your sensor values
 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin1 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin = A1;  // Analog input pin that the potentiometer is attached to
const int analogOutPin1 = 11; // Analog output pin that the LED is attached to
const int analogOutPin = 3; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int sensorValue1 = 0;        // value read from the pot
int outputValue1 = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023/7, 0, 255);  
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);           

  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t output = ");      
  Serial.println(outputValue);   


  sensorValue1 = analogRead(analogInPin1);            
  // map it to the range of the analog out:
  outputValue1 = map(sensorValue1, 0, 1023, 0, 255);  
  // change the analog out value:
  analogWrite(analogOutPin1, outputValue1);           

  // print the results to the serial monitor:
  Serial.print("sensor1 = " );                       
  Serial.print(sensorValue1);      
  Serial.print("\t output1 = "); 
  Serial.println(outputValue1);     

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(100);                     
}

//practice how to set a max and min so it doesn't blink 

