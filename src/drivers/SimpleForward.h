#pragma once
#include "Arduino.h"
#include "Driver.h"
class SimpleForward : public Driver {
public:
  SimpleForward(IRSensors*, DCMotors*, PowerManager*);
  ~SimpleForward();
  void loop();
};