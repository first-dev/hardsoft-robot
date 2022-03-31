#pragma once
#include "modules/IRSensors.h"
#include "modules/DCMotors.h"
#include "modules/PowerManager.h"

class Driver {
protected:
  IRSensors* irSensors;
  DCMotors* dcMotors;
  PowerManager* powerManager;
public:
  Driver(IRSensors*, DCMotors*, PowerManager*);
  virtual ~Driver();
  virtual void loop() = 0;
};