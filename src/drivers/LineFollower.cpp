#include "LineFollower.h"
#define MAX_SPEED 200

LineFollower::LineFollower(IRSensors* irSensors, DCMotors* dcMotors, PowerManager* powerManager)
  : Driver(irSensors, dcMotors, powerManager) {
  dcMotors->setLeftSpeed(MAX_SPEED);
  dcMotors->setRightSpeed(MAX_SPEED);
}
LineFollower::~LineFollower() {}
void LineFollower::loop() {
  if (irSensors->isLeftOnBlack() && !irSensors->isRightOnBlack()) {
    dcMotors->setLeftSpeed(0);
    dcMotors->setRightSpeed(MAX_SPEED);
  } else if (!irSensors->isLeftOnBlack() && irSensors->isRightOnBlack()) {
    dcMotors->setLeftSpeed(MAX_SPEED);
    dcMotors->setRightSpeed(0);
  } else if (!irSensors->isLeftOnBlack() && !irSensors->isRightOnBlack()) {
    dcMotors->setLeftSpeed(MAX_SPEED);
    dcMotors->setRightSpeed(MAX_SPEED);
  } else if (irSensors->isLeftOnBlack() && irSensors->isRightOnBlack()) {
    dcMotors->setLeftSpeed(0);
    dcMotors->setRightSpeed(0);
  }
  // dcMotors->setLeftSpeed(MAX_SPEED);
  // dcMotors->setRightSpeed(MAX_SPEED);
}