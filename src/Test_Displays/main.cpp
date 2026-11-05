#include <Arduino.h>
#include "pins_v1.h"
#include "Actuators.h"
#include "Displays.h"


// uint32_t update =0;

// void setup(){
//     displaysinit();
//     actuatorsinit(10, 9, 8);
// }

// void loop(){
//     uint32_t now = millis();
//     if (now - update >= 100){
//         update = now;
//         displaysupdate(90, 50, true, false);
//         setspeedFan(50);
//     }
// }
void setup(){
    Serial.begin(115200);

    actuatorsinit(PIN_FAN_PWM, PIN_BUZZER, PIN_LED_WARN);
    displaysinit();
    delay(1000);

}

void loop(){
    // quat quay 50%, bat canh bao, LCD lap so gia lap
    setspeedFan(50);
    setWarning(true);
    displaysupdate(95,50,true,true);

    delay(2000);

    //tat quat, tat canh bao
    setspeedFan(0);
    setWarning(false);
    displaysupdate(40, 0, false, false);

    delay(2000);
}
