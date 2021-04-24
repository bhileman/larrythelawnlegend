#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

// stepper has 200 steps in 1 rotation (360 deg)

int incomingData;

Servo myServo;  // create servo object to control a servo

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 1);

int myServoHome;
int myServoPos = 0;    // variable to store the servo position

const int servoSwitchPin = 7;     // the number of the pushbutton pin
const int stepperSwitchPin = 6;

// variables will change:
int servoButtonState = 0;         // variable for reading the pushbutton status
int stepperButtonState = 0;

void setup() {
  // initialize the pushbutton pin as an input:
  Serial.begin(9600);
  pinMode(servoSwitchPin, INPUT);
  pinMode(stepperSwitchPin, INPUT);
  myServo.attach(3);  // attaches the servo on pin 3 to the servo object
  AFMS.begin();  // create with the default frequency 1.6KHz
  homeServo();
  homeStepper();
}

void loop() {
 while (Serial.available()) {
    incomingData = Serial.read();
    if (incomingData == '1') {
      int myServoNewPos = myServoHome - 3;
      myServo.write(myServoNewPos);
    }
  }
}

void homeServo() {
  servoButtonState = digitalRead(servoSwitchPin);
  while (digitalRead(servoSwitchPin)== HIGH) //unpressed
  {
      myServoPos++;
      myServo.write(myServoPos);
      delay(20);
  }
  myServoHome = myServoPos - 12;
  myServo.write(myServoHome);
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
