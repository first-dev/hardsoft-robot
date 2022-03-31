#include <Arduino.h>
#include "drivers/DriversManager.h"

DriversManager dirverManager;

void setup() {
  dirverManager.loadDriver(DriversManager::LINE_FOLLOWER);
}

void loop() {
  dirverManager.loop();
}