#include <Arduino.h>
#include "pins_v1.h"
#include "Actuators.h"

uint32_t toggle =0;
bool iswarning = false;
uint32_t fanspeed = 0;
void setup(){
    // Serial.begin(115200);
    actuatorsinit(PIN_FAN_PWM, PIN_BUZZER, PIN_LED_WARN);
}

void loop(){
    uint32_t now = millis();
    if(now - toggle >= 2000){
        toggle = now;
        iswarning = !iswarning;
        setWarning(iswarning);

        fanspeed += 25;
        if(fanspeed > 100) fanspeed =0;
        setspeedFan(fanspeed);
    }
}


// #include <Arduino.h>
// #include "pins_v1.h"

// void setup() {
//   pinMode(PIN_FAN_PWM, OUTPUT);
//   pinMode(PIN_LED_WARN, OUTPUT);
//   pinMode(PIN_BUZZER, OUTPUT);
// }

// void loop() {
//   digitalWrite(PIN_LED_WARN, HIGH);
//   digitalWrite(PIN_BUZZER, HIGH);
//   analogWrite(PIN_FAN_PWM, 128);
//   delay(2000);

//   digitalWrite(PIN_LED_WARN, LOW);
//   digitalWrite(PIN_BUZZER, LOW);
//   analogWrite(PIN_FAN_PWM, 255);
//   delay(2000);
// }


// #include <Arduino.h>
// #include "Actuators.h"

// void setup(){
//     // Khởi tạo: Quạt(10), Còi(2), LED(3) cho khớp với hình Proteus
//     actuatorsinit(10, 2, 3); 
// }

// void loop(){
//     setspeedFan(128);  // Cho quạt quay 50% ga
//     setWarning(true);  // Bật đèn LED và Còi lên
//     delay(1000);
// }