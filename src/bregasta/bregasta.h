#pragma once
#include <Arduino.h>

class Bregasta {
public:
    Bregasta(uint8_t pin);
    static unsigned long getBregastaLastTime() { return s_BregastaTime; }
    static unsigned long getRPM() { 
        return s_FirstReadFlag ? 
            (((60.L * 1000.L * 1000.L) / s_BregastaTime) * 2) : 
            0.L;
    }

    static uint32_t s_BregastaCounter;
    static bool s_IsActivated;
    
private:
    static bool s_FirstReadFlag;
    static unsigned long s_LTime;
    static unsigned long s_BregastaTime;

    
    
    static void interrupt_citaj_Bregasta();

    uint8_t PIN_BREGASTA;
};