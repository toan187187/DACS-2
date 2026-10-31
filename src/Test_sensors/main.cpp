#include <Arduino.h>
#include "pins_v1.h"
#include "Sensors.h"

uint32_t lastprint = 0; 

void setup(){
    Serial.begin(115200);
    SensorInit(PIN_TEMP, PIN_THROTTLE, PIN_BRAKE);
}

void loop(){
    uint32_t now = millis();

    if(now - lastprint >= 50){
        lastprint = now;

        SensorsData data = sensorsread();

        Serial.print("nhietdo: ");
        Serial.print(data.nhietdotho);

        Serial.print("\t | ga: ");
        Serial.print(data.vatga);
        Serial.print(" -> ");
        Serial.print((data.vatga >=0 && data.vatga <= 100) ? "PASS" : "FAIL");

        Serial.print("\t | phanh: ");
        if(data.trangthaiphanh){
            Serial.println("[DA NHAN]");
        } else {
            Serial.println("[Nha]");
        }
    }

}