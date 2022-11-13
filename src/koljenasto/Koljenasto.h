#pragma once
#include <Arduino.h>

class Koljenasto {
public:
    Koljenasto(uint8_t pin);
    static unsigned long getPinDeltaTime() { return s_CurrDeltaTime; }
    static unsigned long getPinLastPosReadTime() { return s_LastReadTime; }
    static unsigned long getKoljLastTime() { return s_CurrGMTDeltaTime; }
    static unsigned long getRPM() { 
        return (60.0 * 1000.0 * 1000.0) / s_CurrGMTDeltaTime;
    }
    static uint32_t getCurrPin() { return s_PinCounter; }
private:
    static unsigned long s_LastReadTime;
    static unsigned long s_CurrDeltaTime;
    static unsigned long s_LastDeltaTime;
    static uint32_t s_PinCounter;

    static bool s_FirstFlag;

    static unsigned long s_LastGMTReadTime;
    static unsigned long s_CurrGMTDeltaTime;

    static void interrupt_citaj_koljenasto();

    uint8_t PIN_KOLJENASTO;
};