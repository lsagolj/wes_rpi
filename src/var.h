#include <Arduino.h>
#include <Timer.h>

#define A A0 
#define koljeno 2

int ulaz = 0;
int koljeno_val;
int last_val = 0;
int counter = 0;

float f_min;
float napon = 0;

uint32_t proslo_vrijeme = 0;
uint32_t x = 0;

bool minimum = false;

Timer timer(MICROS);
Timer bounce(MICROS);

void rpm();