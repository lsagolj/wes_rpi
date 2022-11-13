#include "Koljenasto.h"

unsigned long Koljenasto::s_LastReadTime = 0.0;
unsigned long Koljenasto::s_CurrDeltaTime = 0.0;
unsigned long Koljenasto::s_LastDeltaTime = 0.0;
uint32_t Koljenasto::s_PinCounter = -999999;
unsigned long Koljenasto::s_LastGMTReadTime = 0.0;
unsigned long Koljenasto::s_CurrGMTDeltaTime = 0.0;

bool Koljenasto::s_FirstFlag = true;

Koljenasto::Koljenasto(uint8_t pin) : PIN_KOLJENASTO(pin) {
    
    pinMode(PIN_KOLJENASTO, INPUT); 
    attachInterrupt(digitalPinToInterrupt(PIN_KOLJENASTO), interrupt_citaj_koljenasto, RISING);
}

void Koljenasto::interrupt_citaj_koljenasto() {
    unsigned long currTime = micros();
    if (s_FirstFlag) {
        s_LastReadTime = currTime;
        s_CurrGMTDeltaTime = 0.0;
        s_LastGMTReadTime = currTime;
        s_PinCounter = 0;
        s_FirstFlag = false;
    }

    s_CurrDeltaTime = currTime - s_LastReadTime;
    
    

    // Ako je vremenski razmak oko 2 pina onda smo na 1. pinu
    if (s_CurrDeltaTime > s_LastDeltaTime * 2.5) {
        s_CurrGMTDeltaTime = currTime - s_LastGMTReadTime;
        s_LastGMTReadTime = currTime;
        s_PinCounter = 0;
    }

    // Ako je prvi put program pokrenut
    

    s_LastReadTime = currTime;
    
    s_LastDeltaTime = s_CurrDeltaTime;
    s_PinCounter++;
}