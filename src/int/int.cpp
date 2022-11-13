#include "int.h"


Inter::Inter(uint8_t pin) : PIN_INT(pin) {
    
    pinMode(PIN_INT, OUTPUT); 
    attachInterrupt(digitalPinToInterrupt(PIN_INT), sendPulse, RISING);
    attachInterrupt(digitalPinToInterrupt(PIN_INT), pucajIskru, FALLING);
}

void Inter::sendPulse() 
{
    digitalWrite(8, 1);                 //Stavlja pin 8 u val 1
    delayMicroseconds(1500);            //Necmo irl koristiti delay al ovo tek tolko da vidimo kako radi   
    digitalWrite(8, 0); 
}

void Inter::pucajIskru() 
{
    Serial.println("a00");
}