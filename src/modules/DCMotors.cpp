#include "DCMotors.h"

DCMotors::DCMotors(byte IN1Pin, byte IN2Pin, byte IN3Pin, byte IN4Pin) {
  this->IN1Pin = IN1Pin;
  this->IN2Pin = IN2Pin; // PWM
  this->IN3Pin = IN3Pin;
  this->IN4Pin = IN4Pin; // PWM
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);
  // leftSpeed = 0;
  // rightSpeed = 0;
}
void DCMotors::loop() {
  long currentMills = millis();
  long millsDiff = currentMills - lastLoopMills;
  long requiredSteps = millsDiff * acceleration / 1000;



  lastLoopMills = currentMills;
}

void DCMotors::apply() {
  if (leftSpeed >= 0) {
    digitalWrite(IN1Pin, 1);
    analogWrite(IN2Pin, 255 - leftSpeed);
  } else {
    digitalWrite(IN1Pin, 0);
    analogWrite(IN2Pin, -leftSpeed);
  }
  if (rightSpeed >= 0) {
    digitalWrite(IN3Pin, 1);
    analogWrite(IN4Pin, 255 - rightSpeed);
  } else {
    digitalWrite(IN3Pin, 0);
    analogWrite(IN4Pin, -rightSpeed);
  }
}

void DCMotors::setRightSpeed(int value) {
  targetRightSpeed = value;
  rightSpeed = value;
  apply();
}
int DCMotors::getRightSpeed() {
  return rightSpeed;
  return targetRightSpeed;
}
void DCMotors::setLeftSpeed(int value) {
  targetLeftSpeed = value;
  leftSpeed = value;
  apply();
}
int DCMotors::getLeftSpeed() {
  return leftSpeed;
  return targetLeftSpeed;
}
void DCMotors::setAcceleration(float value) {
  acceleration = value;
}
float DCMotors::getAcceleration() {
  return acceleration;
}