/*
This code corresponds to a floating boat with rudimentary sensing capabilities - 
 step by step instructions and images are at levinegabriella.com/teaching
 It includes an parallax ultrasonic rangefinder :  see data sheet
 http://www.arduino.cc/en/Tutorial/Ping
 which allows the boat to turn away from obstacles ahead.
 It also includes two reed switches so if it hits barriers from the side, it 
 turns around away from the wall
 
 created 2011 by gabriella levine
 */

// constants
// set pin numbers:
const int pingPin = 7;
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int buttonPin2 = 4;
const int motor =  3;      // the number of the motor pin
const int motor2=11;

// variables 
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState1  =0;
void setup() {
  //begin serial
  Serial.begin(9600);
  // initialize the motors  as output:
  pinMode(motor, OUTPUT); 
  pinMode(motor2, OUTPUT);  
  // initialize the pushbutton pins as  input:
  pinMode(buttonPin1, INPUT);    
  pinMode(buttonPin2, INPUT); 
}

void loop(){
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
//  long duration, inches, cm;
//  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
//  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
//  pinMode(pingPin, OUTPUT);
//  digitalWrite(pingPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(pingPin, HIGH);
//  delayMicroseconds(5);
//  digitalWrite(pingPin, LOW);
  
   // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
 // duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
//  inches = microsecondsToInches(duration);
//  cm = microsecondsToCentimeters(duration);
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState = digitalRead(buttonPin2);
//  if (cm<=15){
//    //digitalWrite(motor, LOW); 
    digitalWrite(motor2, HIGH);
 // }
 // else{
    //digitalWrite(motor, HIGH);
    digitalWrite(motor, HIGH);
  //  button();
  //}
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

