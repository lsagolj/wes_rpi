#pragma once
#include <Arduino.h>

class Koljenasto {
public:
    Koljenasto(uint8_t pin);
    static unsigned long getKoljLastTime() { return s_KoljTime; }
    static unsigned long getRPM() { 
        return s_FirstReadFlag ? 
            (60.UL * 1000.UL * 1000.UL) / s_KoljTime : 
            0.UL;
    }
private:
    static bool s_FirstReadFlag;
    static unsigned long s_LTime;
    static unsigned long s_KoljTime;
    static uint32_t s_KoljCounter;
    static void interrupt_citaj_koljenasto();

    uint8_t PIN_KOLJENASTO;
};