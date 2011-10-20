/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int pingPin = 7;
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int buttonPin2 = 4;
const int motor =  3;      // the number of the LED pin
const int motor2=11;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState1  =0;
void setup() {
    Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(motor, OUTPUT); 
pinMode(motor2, OUTPUT);  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);    
 pinMode(buttonPin2, INPUT); 
}

void loop(){
    long duration, inches, cm;
     pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
   pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState = digitalRead(buttonPin2);
 if (cm<=15){
   //digitalWrite(motor, LOW); 
   digitalWrite(motor2, LOW);
  }
  else{
//digitalWrite(motor, HIGH);
digitalWrite(motor2, HIGH);
button();
}
delay(100);


}
void button(){
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {     
    // turn LED on:    
    digitalWrite(motor, LOW);  
  } 
  else {
    // turn LED off:
    digitalWrite(motor, HIGH); 
  }
 if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(motor2, LOW);  
  } 
  else {
    // turn LED off:
    digitalWrite(motor2, HIGH); 
  }
}
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
//put on git
