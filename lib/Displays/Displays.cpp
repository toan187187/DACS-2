#include "Displays.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void displaysinit(){
    lcd.init();
    lcd.backlight();

    lcd.setCursor(0,0);
    lcd.print("ECU V1 ready...");
}

void displaysupdate(uint8_t temp, uint8_t throttle, uint8_t brake, bool warming){
    lcd.setCursor(0,0);
    lcd.print("Ga:");
    if(throttle < 100) lcd.print(" ");
    if(throttle < 10) lcd.print(" ");
    lcd.print(throttle);
    lcd.print("% ");
    lcd.print(brake ? "[Phanh]" : "     ");

    lcd.setCursor(0,1);
    lcd.print("Temp:");
    lcd.print(temp);
    lcd.print("C  ");
    lcd.print(warming ? "!WARM!" : "     ");
}