#ifndef AUTUATORS_H
#define AUTUATORS_H
#include<Arduino.h>

// không được dùng struct -> bắt phải dùng hàm riêng lẻ là void() + điều khiển độc lập + cách ly phần cứng.

void actuatorsinit(uint8_t pinFan, uint8_t pinBuzzer, uint8_t pinLed);
void setspeedFan(uint8_t speedfan);
void setWarning(bool warning);

#endif