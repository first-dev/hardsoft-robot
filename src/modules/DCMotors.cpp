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
}

void DCMotors::loop() {
  unsigned long currentMills = millis();
  if (lastLoopMills == 0) {
    lastLoopMills = currentMills;
    return;
  }
  long millsDiff = currentMills - lastLoopMills;
  int requiredSteps = millsDiff * acceleration / 1000;
  if (requiredSteps == 0) return;
  if (leftSpeed != targetLeftSpeed)
    leftSpeed = animateSpeed(leftSpeed, targetLeftSpeed, requiredSteps);
  if (rightSpeed != targetRightSpeed)
    rightSpeed = animateSpeed(rightSpeed, targetRightSpeed, requiredSteps);
  apply();
  lastLoopMills = currentMills;
}

int DCMotors::animateSpeed(int speed, int targetSpeed, int requiredSteps) {
  if (targetSpeed > speed) {
    if (requiredSteps <= targetSpeed - speed) {
      speed += requiredSteps;
    } else {
      speed = targetSpeed;
    }
  } else if (targetSpeed < speed) {
    if (requiredSteps <= speed - targetSpeed) {
      speed -= requiredSteps;
    } else {
      speed = targetSpeed;
    }
  }
  return speed;
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
  if (acceleration < 0)
    rightSpeed = value;
  apply();
}
int DCMotors::getRightSpeed() {
  return rightSpeed;
}
void DCMotors::setLeftSpeed(int value) {
  targetLeftSpeed = value;
  if (acceleration <= 0)
    leftSpeed = value;
  apply();
}
int DCMotors::getLeftSpeed() {
  return leftSpeed;
}
void DCMotors::setAcceleration(float value) {
  acceleration = value;
}
float DCMotors::getAcceleration() {
  return acceleration;
}