#include "Koljenasto.h"

unsigned long Koljenasto::s_LastReadTime = 0.0;
unsigned long Koljenasto::s_CurrDeltaTime = 0.0;
unsigned long Koljenasto::s_LastDeltaTime = 0.0;
uint32_t Koljenasto::s_PinCounter = 0;
unsigned long Koljenasto::s_LastGMTReadTime = 0.0;
unsigned long Koljenasto::s_CurrGMTDeltaTime = 0.0;

Koljenasto::Koljenasto(uint8_t pin) : PIN_KOLJENASTO(pin) {
    
    pinMode(PIN_KOLJENASTO, INPUT); 
    attachInterrupt(digitalPinToInterrupt(PIN_KOLJENASTO), interrupt_citaj_koljenasto, RISING);
}

void Koljenasto::interrupt_citaj_koljenasto() {
    s_CurrDeltaTime = micros() - s_LastReadTime;
    s_LastReadTime = micros();
    // Ako je vremenski razmak oko 2 pina onda smo na 1. pinu
    if (s_CurrDeltaTime > s_LastDeltaTime * 2.5 && s_CurrDeltaTime < s_LastDeltaTime * 3.5) {
        s_PinCounter = 0;
    }

    // GMT Triggered, 9 = krecemo od 0
    if (s_PinCounter == 9) {
        s_CurrGMTDeltaTime = micros() - s_LastGMTReadTime;
        s_LastGMTReadTime = micros();
    }
    
    s_LastDeltaTime = s_CurrDeltaTime;
    s_PinCounter++;
}