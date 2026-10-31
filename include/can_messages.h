#ifndef CAN_MESSAGES_H
#define CAN_MESSAGES_H

#include <Arduino.h>

#define CAN_ID_SENSOR_DATA 0x100

struct __attribute__((packer)) SensorDataMsg{

    uint8_t nhietdotho;  //(0-255) de vua 1 byte trong CAN
    uint8_t vatga;
    uint8_t trangthaiphanh;
    uint8_t reserved[5];
};
#endif