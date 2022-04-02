#pragma once
#include <Arduino.h>

class DCMotors {
public:
  DCMotors(byte IN1Pin = 2, byte IN2Pin = 3, byte IN3Pin = 4, byte IN4Pin = 5);
  // needed for acceleration
  void loop();

  void setRightSpeed(int value);
  int getRightSpeed();
  void setLeftSpeed(int value);
  int getLeftSpeed();
  void setAcceleration(float value);
  float getAcceleration();

private:
  byte IN1Pin, IN2Pin, IN3Pin, IN4Pin;
  // max speed: 255 | min speed: -255
  int leftSpeed = 0, rightSpeed = 0, targetLeftSpeed = 0, targetRightSpeed = 0;
  // acceleration = speed/second (set a negative value to disable)
  float acceleration = 100;
  // last time loop executed
  unsigned long lastLoopMills = 0;
  // apply speeds to hardware
  void apply();
  // animate speed to targetSpeed (acceleration)
  int animateSpeed(int speed, int targetSpeed, int requiredSteps);
};