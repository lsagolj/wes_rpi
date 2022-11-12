#pragma once
#include <Arduino.h>

class Koljenasto {
public:
    Koljenasto(uint8_t pin);
    static unsigned long getKoljLastTime() { return s_KoljTime; }
    static unsigned long getRPM() { 
        return s_FirstReadFlag ? 
            (60.L * 1000.L * 1000.L) / s_KoljTime : 
            0.L;
    }
private:
    static bool s_FirstReadFlag;
    static unsigned long s_LTime;
    static unsigned long s_KoljTime;
    static uint32_t s_KoljCounter;
    static void interrupt_citaj_koljenasto();

    uint8_t PIN_KOLJENASTO;
};