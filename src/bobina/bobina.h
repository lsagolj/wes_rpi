#pragma once
#include <Arduino.h>

#define punjenje_us 1500 //Trajanje od 1.5 ms


unsigned long s_LastReadTime;
unsigned long s_CurrDeltaTime;
unsigned long s_LastDeltaTime;



void saljiBobinu();