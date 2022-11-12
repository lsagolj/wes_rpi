#include "Koljenasto.h"

uint32_t Koljenasto::s_KoljCounter = -1;
unsigned long Koljenasto::s_KoljTime = 0;
unsigned long Koljenasto::s_LTime = 0;
bool Koljenasto::s_FirstReadFlag = false;

Koljenasto::Koljenasto(uint8_t pin) : PIN_KOLJENASTO(pin) {
    
    pinMode(PIN_KOLJENASTO, INPUT); 
    attachInterrupt(digitalPinToInterrupt(PIN_KOLJENASTO), interrupt_citaj_koljenasto, RISING);
}

void Koljenasto::interrupt_citaj_koljenasto() {
    if (s_KoljCounter % 22 == 10) {
        s_FirstReadFlag = true;
        s_KoljTime = micros() - s_LTime;
        s_LTime = micros();
    }
    s_KoljCounter++;
}