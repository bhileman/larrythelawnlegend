#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  AFMS.begin();
  myMotor.setSpeed(20);
}

void loop() {
  // put your main code here, to run repeatedly:
  step(200, FORWARD, MICROSTEP)

}
