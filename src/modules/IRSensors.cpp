#include "IRSensors.h"

IRSensors::IRSensors(byte leftIRPin, byte rightIRPin) {
  this->leftIRPin = leftIRPin;
  this->rightIRPin = rightIRPin;
  pinMode(leftIRPin, INPUT_PULLUP);
  pinMode(rightIRPin, INPUT_PULLUP);
  pinMode(leftIRPin + 1, OUTPUT);
  pinMode(leftIRPin + 2, OUTPUT);
  pinMode(rightIRPin + 1, OUTPUT);
  pinMode(rightIRPin + 2, OUTPUT);
  digitalWrite(leftIRPin + 1, 0);
  digitalWrite(leftIRPin + 2, 1);
  digitalWrite(rightIRPin + 1, 0);
  digitalWrite(rightIRPin + 2, 1);
}

IRSensors::IRSensors(byte leftIRPin, byte middlePin, byte rightIRPin) {
  this->leftIRPin = leftIRPin;
  this->rightIRPin = rightIRPin;
  this->middlePin = middlePin;
  pinMode(leftIRPin, INPUT_PULLUP);
  pinMode(rightIRPin, INPUT_PULLUP);
  pinMode(middlePin, INPUT_PULLUP);
}

bool IRSensors::isLeftOnBlack() {
  return digitalRead(leftIRPin);
}
bool IRSensors::isRightOnBlack() {
  return digitalRead(rightIRPin);
}