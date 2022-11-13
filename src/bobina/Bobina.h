#pragma once
#include <Arduino.h>

class Bobina {
public:
    Bobina();
    uint32_t getAngle(uint32_t pressure, uint32_t rpm);
    uint32_t sendPulse();
private:
    uint32_t getPaInt(uint32_t pressure);
};