#include "PowerManager.h"

PowerManager::PowerManager() {}

void PowerManager::setToGround(byte pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, 0);
}
void PowerManager::setToVcc(byte pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, 1);
}