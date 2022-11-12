#include "bobina.h"

Bobina::Bobina(uint8_t pin) : PIN_BOBINA(pin) 
{    
    pinMode(PIN_BOBINA, OUTPUT); 
}