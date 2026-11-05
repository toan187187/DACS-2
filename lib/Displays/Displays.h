#ifndef DISPLAYS_H
#define DISPLAYS_H

#include <Arduino.h>
void displaysinit();

void displaysupdate(uint8_t temp, uint8_t throttle, uint8_t brake, bool warming);
#endif