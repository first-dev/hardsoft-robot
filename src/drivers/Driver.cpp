#include "Driver.h"

Driver::Driver(IRSensors* irSensors, DCMotors* dcMotors, PowerManager* powerManager) {
  this->irSensors = irSensors;
  this->dcMotors = dcMotors;
  this->powerManager = powerManager;
}

Driver::~Driver() {}