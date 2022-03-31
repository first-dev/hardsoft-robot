#pragma once
#include "Arduino.h"
#include "Driver.h"
class LineFollower : public Driver {
public:
  LineFollower(IRSensors*, DCMotors*, PowerManager*);
  ~LineFollower();
  void loop();
};