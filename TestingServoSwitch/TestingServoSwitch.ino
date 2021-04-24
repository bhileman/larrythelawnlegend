#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

Servo myServo;  // create servo object to control a servo

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 1);

int myServoPos = 0;    // variable to store the servo position

// constants won't change. They're used here to set pin numbers:
const int servoSwitchPin = 7;     // the number of the pushbutton pin
const int stepperSwitchPin = 6;

// variables will change:
int servoButtonState = 0;         // variable for reading the pushbutton status
int stepperButtonState = 0;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(servoSwitchPin, INPUT);
  pinMode(stepperSwitchPin, INPUT);
  myServo.attach(3);  // attaches the servo on pin 3 to the servo object
  AFMS.begin();  // create with the default frequency 1.6KHz
  homeServo();
  homeStepper();
}

void loop() {
 
}

void homeServo() {
  servoButtonState = digitalRead(servoSwitchPin);
  while (digitalRead(servoSwitchPin)== HIGH) //unpressed
  {
      myServoPos++;
      myServo.write(myServoPos);
      delay(20);
  }
  myServoPos = myServoPos - 12;
  myServo.write(myServoPos);
  delay(500);
}

void homeStepper() {
  myMotor->setSpeed(3);  // 5 rpm 
  stepperButtonState = digitalRead(stepperSwitchPin);

  while (digitalRead(stepperSwitchPin)== HIGH) //unpressed
  {
      myMotor->step(1, BACKWARD, DOUBLE);
      delay(10); 
  }
  myMotor->step(5, FORWARD, DOUBLE);
  delay(1000);
  myMotor->release();  // release motor
}
