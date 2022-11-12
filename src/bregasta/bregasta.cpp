#include "bregasta.h"

uint32_t Bregasta::s_BregastaCounter = -1;
unsigned long Bregasta::s_BregastaTime = 0;
unsigned long Bregasta::s_LTime = 0;
bool Bregasta::s_FirstReadFlag = false;

Bregasta::Bregasta(uint8_t pin) : PIN_Bregasta(pin) {
    
    pinMode(PIN_Bregasta, INPUT); 
    attachInterrupt(digitalPinToInterrupt(PIN_Bregasta), interrupt_citaj_Bregasta, RISING);
}

void Bregasta::interrupt_citaj_Bregasta() {
    if (s_BregastaCounter % 22 == 10) {
        s_FirstReadFlag = true;
        s_BregastaTime = micros() - s_LTime;
        s_LTime = micros();
    }
    s_BregastaCounter++;
}