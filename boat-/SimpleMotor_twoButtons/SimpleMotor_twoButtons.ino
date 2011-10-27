
/*
This sketch is designed for a boat with two motors, and two buttons. The buttons are meant to act as
edge detection - If one button is pressed, one motor stops, therefore the boat can steer away from the 
obstacle.

See levinegabriella.com/teaching for step by step on construction, code, and circuit

Two circuits include : button : 
 http://www.arduino.cc/en/Tutorial/Button
 
 and powering a high current load using a transistor : see


*/
// constants won't change. They're used here to 
// set pin numbers:

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

  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState = digitalRead(buttonPin2);

  digitalWrite(motor, HIGH);
  digitalWrite(motor2, HIGH);
  button();

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

//check this
//make a readme explaining all the tutorials - beginners etc others
//make a list on github of your website and other tutorials
//start a google group
//make a LIST Of learning resources
