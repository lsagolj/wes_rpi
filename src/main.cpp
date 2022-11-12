#include <Arduino.h>
#include <Timer.h>

const int A = A0;  
const int koljeno = 2;

int ulaz = 0;
int koljeno_val;
int last_val = 0;
int counter = 0;

float f_min;
float napon = 0;

uint32_t proslo_vrijeme = 0;
uint32_t x = 0;

Timer timer(MICROS);
Timer bounce(MICROS);

void rpm();

void setup() 
{
  pinMode(koljeno, INPUT); 	
  pinMode(A, INPUT); 	

  attachInterrupt(digitalPinToInterrupt(koljeno), rpm, RISING);


  Serial.begin(9600);
}

void loop() 
{
  f_min = 1 / ((float)x / 1000.f / 1000.f);               //Pretvaranje iz vremena u frekvenciju
  Serial.println(f_min);                                  //Printanje frekvencije

}

void rpm()
{
  if(timer.state() != RUNNING && counter % 10 == 0)       //Ako tajmer nije pokrenut, no brojimo samo svaki 10 rise
  {
    timer.start();
  }
  else
  {
    timer.pause();
    x = timer.read();
  }
  counter++;
}