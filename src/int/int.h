#pragma once
#include <Arduino.h>

class Inter {
public:
    Inter(uint8_t pin);
    
private:
    static void sendPulse();
    static void pucajIskru();
    
    uint8_t PIN_INT;
};