#ifndef SENSORS_H
#define SENSORS_H
#include <Arduino.h>

struct SensorsData     // dễ dàng đóng gói, đọc dữ liệu đòng bộ 
{
    /* data */
    uint8_t nhietdotho;  //(0-255) de vua 1 byte trong CAN
    uint8_t vatga;
    bool trangthaiphanh;
};

void SensorInit(uint8_t channhietdo, uint8_t changa, uint8_t chanphanh);   // KHỞI TẠO CHÂN CẮM

SensorsData sensorsread();        // TRẢ VỀ DỮ LIỆU

#endif