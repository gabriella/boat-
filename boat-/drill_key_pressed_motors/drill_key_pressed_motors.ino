

// These constants won't change.  They're used to give names
// to the pins used:
int incomingData;

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin9 = 3; // Analog output pin that the LED is attached to
const int analogOutPin5 = 5;
const int analogOutPin11 = 11; // Analog output pin that the LED is attached to
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
boolean power=false;
int pinState=0;
int lastPinState=0;
//int zState = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  
  Serial.begin(9600); 
  //Serial.println("begin");
}

void loop() {

   
  if(Serial.available()>0){
    incomingData = Serial.read();
    Serial.print(incomingData, DEC);}
    //Serial.println("data: ");
   // Serial.println(incomingData);


if(incomingData=='1')
{
analogWrite(analogOutPin11, 75);
analogWrite(analogOutPin9, 75);
analogWrite(analogOutPin5, 75);

}
else if(incomingData=='2')
{
analogWrite(analogOutPin11, 90);

analogWrite(analogOutPin9, 90);
analogWrite(analogOutPin5, 90);
}
else if(incomingData=='3')
{
analogWrite(analogOutPin11, 120);
analogWrite(analogOutPin9, 120);
analogWrite(analogOutPin5, 120);
}
else if(incomingData=='4')
{
analogWrite(analogOutPin11, 140);
analogWrite(analogOutPin9, 140);
analogWrite(analogOutPin5, 140);
}
else if(incomingData=='5')
{
analogWrite(analogOutPin11, 150);
analogWrite(analogOutPin9, 150);
analogWrite(analogOutPin5, 150);
}
else if(incomingData=='6')
{
analogWrite(analogOutPin11, 175);
analogWrite(analogOutPin9, 175);
analogWrite(analogOutPin5, 175);
}
else if(incomingData=='7')
{
analogWrite(analogOutPin11, 200);
analogWrite(analogOutPin9, 200);
analogWrite(analogOutPin5, 200);
}
else if(incomingData=='8')
{
analogWrite(analogOutPin11, 255);
analogWrite(analogOutPin9, 255);
analogWrite(analogOutPin5, 255);
}
else if(incomingData=='9')
{
analogWrite(analogOutPin11, 255);
analogWrite(analogOutPin9, 255);
analogWrite(analogOutPin5, 255);
}
else if(incomingData=='0')
{
analogWrite(analogOutPin11, 0);
analogWrite(analogOutPin9, 0);
analogWrite(analogOutPin5, 0);
}
else {analogWrite(analogOutPin11, 0);}

}
//alternative is to go through a couple 440 k resistors
//transisotrs seem to take quite a bit of amperage so I cant power the LED at the same time
