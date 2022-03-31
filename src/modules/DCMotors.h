#pragma once
#include <Arduino.h>

class DCMotors {
public:
  DCMotors(byte IN1Pin = 2, byte IN2Pin = 3, byte IN3Pin = 4, byte IN4Pin = 5);
  void loop();

  void setRightSpeed(int value);
  int getRightSpeed();
  void setLeftSpeed(int value);
  int getLeftSpeed();
  void setAcceleration(float value);
  float getAcceleration();

  // void stop();
  // void forward();
  // void reverse();
  // void left();
  // void right();

private:
  byte IN1Pin, IN2Pin, IN3Pin, IN4Pin;
  int leftSpeed = 0, rightSpeed = 0, targetLeftSpeed = 0, targetRightSpeed = 0;
  float acceleration = 1000;
  long lastLoopMills = 0;
  void apply();
  void initSpeeds();
};