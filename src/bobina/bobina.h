#pragma once
#include <Arduino.h>

class Bobina {
public:
    Bobina(uint8_t pin);

private:
    uint8_t PIN_BOBINA;
};