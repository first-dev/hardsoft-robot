#pragma once
#include "Driver.h"
#include "SimpleForward.h"
#include "LineFollower.h"
#include "../modules/DCMotors.h"
#include "../modules/PowerManager.h"
#include "../modules/IRSensors.h"

class DriversManager {
public:
  enum DriverEnum {
    NONE,
    SIMPLE_FORWARD,
    LINE_FOLLOWER
  };
  DriversManager();
  void loadDriver(DriverEnum);
  void unloadDriver();
  void loop();
  DriverEnum getActiveDriverEnum();
private:
  DriverEnum activeDriverEnum;
  Driver* driver;
  DCMotors* dcMotors;
  PowerManager* powerManager;
  IRSensors* irSensor;
};