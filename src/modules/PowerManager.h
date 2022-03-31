#pragma once
#include "Arduino.h"

class PowerManager {
public:
  PowerManager();
  void setToVcc(byte pin);
  void setToGround(byte pin);
};