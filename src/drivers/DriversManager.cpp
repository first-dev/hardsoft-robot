#include "DriversManager.h"

DriversManager::DriversManager() {
  driver = NULL;
  activeDriverEnum = NONE;
  irSensor = new IRSensors(8, 11);
  dcMotors = new DCMotors(2, 3, 4, 5);
  powerManager = new PowerManager();
}
DriversManager::DriverEnum DriversManager::getActiveDriverEnum() {
  return activeDriverEnum;
}
void DriversManager::loadDriver(DriversManager::DriverEnum driverEnum) {
  if (driver != NULL) unloadDriver();
  activeDriverEnum = driverEnum;
  switch (activeDriverEnum) {
  case DriverEnum::SIMPLE_FORWARD:
    driver = new SimpleForward(irSensor, dcMotors, powerManager);
    break;
  case DriverEnum::LINE_FOLLOWER:
    driver = new LineFollower(irSensor, dcMotors, powerManager);
    break;
  case DriverEnum::NONE:
    driver = NULL;
  }
}
void DriversManager::unloadDriver() {
  delete driver;
  driver = NULL;
  activeDriverEnum = NONE;
}

void DriversManager::loop() {
  if (driver != NULL)
    driver->loop();
}