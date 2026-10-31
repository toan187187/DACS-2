#include "Sensors.h"

static uint8_t _channhietdo;
static uint8_t _changa;
static uint8_t _chanphanh;

void SensorInit(uint8_t channhietdo, uint8_t changa, uint8_t chanphanh){
    _channhietdo = channhietdo;
    _changa =changa;
    _chanphanh = chanphanh;

    pinMode(_changa, INPUT_PULLUP);
};



SensorsData sensorsread(){
    SensorsData data;

    int rawnhietdo = analogRead(_channhietdo);
    data.nhietdotho = map(rawnhietdo, 0,1023,0,255);

    int rawga = analogRead(_changa);
    data.vatga = map(rawga, 0,1023, 0, 100);

    data.trangthaiphanh = digitalRead(_chanphanh) == LOW;

    return data;
}
