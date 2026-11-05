#include "Actuators.h"

static uint8_t _pinFan;
static uint8_t _pinBuzzer;
static uint8_t _pinLed;

void actuatorsinit(uint8_t pinFan, uint8_t pinBuzzer, uint8_t pinLed){
    _pinFan = pinFan;
    _pinBuzzer = pinBuzzer;
    _pinLed = pinLed;


    pinMode(_pinFan, OUTPUT);
    pinMode(_pinBuzzer, OUTPUT);
    pinMode(_pinLed, OUTPUT);

    analogWrite(_pinFan, 0);
    digitalWrite(_pinBuzzer, LOW);
    digitalWrite(_pinLed, LOW);
}

void setspeedFan(uint8_t speedfan){
    if(speedfan > 100){
        speedfan = 100;
    }
    uint8_t pvmspeed = map(speedfan, 0 ,100, 0,255);
    analogWrite(_pinFan, pvmspeed);
}

void setWarning(bool warning){
    digitalWrite(_pinBuzzer, warning ? HIGH : LOW);
    digitalWrite(_pinLed, warning ? HIGH : LOW);
}