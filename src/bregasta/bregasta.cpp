#include "bregasta.h"

uint32_t Bregasta::s_BregastaCounter = 1;
unsigned long Bregasta::s_BregastaTime = 0;
unsigned long Bregasta::s_LTime = 0;
bool Bregasta::s_FirstReadFlag = false;

bool Bregasta::s_IsActivated = false;

Bregasta::Bregasta(uint8_t pin) : PIN_BREGASTA(pin) 
{    
    pinMode(PIN_BREGASTA, INPUT); 
    attachInterrupt(digitalPinToInterrupt(PIN_BREGASTA), interrupt_citaj_Bregasta, RISING);
}

void Bregasta::interrupt_citaj_Bregasta() {
    s_IsActivated = true;
    /*if (s_BregastaCounter > -1) {
        s_FirstReadFlag = true;
        s_BregastaTime = micros() - s_LTime;
        s_LTime = micros();
    }
    s_BregastaCounter++;*/
}