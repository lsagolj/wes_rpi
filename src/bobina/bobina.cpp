#include "Bobina.h"

uint32_t tablica[10][5] = {
{18, 25, 34, 38, 42},
{15, 23, 30, 40, 40},
{14, 21, 28, 38, 38},
{14, 20, 25, 36, 36},
{13, 20, 24, 35, 35},
{13, 19, 24, 33, 33},
{13, 19, 23, 32, 32},
{13, 19, 22, 30, 30},
{13, 18, 21, 28, 28},
{13, 18, 20, 25, 25},
};

/*  {13, 13, 13, 13, 13, 13, 14, 14, 15, 18},
    {18, 18, 19, 19, 19, 20, 20, 21, 23, 25},
    {20, 21, 22, 23, 24, 24, 25, 28, 30, 34},
    {25, 28, 30, 32, 33, 35, 36, 38, 40, 38},
    {25, 28, 30, 32, 33, 35, 36, 38, 40, 42}*/

Bobina::Bobina() {

}

uint32_t Bobina::getAngle(uint32_t pressure, uint32_t rpm) {
    if (rpm == 0)
        return 0;

    if (rpm < 1200) {
        return 10;
    } else if (rpm < 1600) {
        return tablica[getPaInt(pressure)][0];
    } else if (rpm < 2150) {
        return tablica[getPaInt(pressure)][1];
    } else if (rpm < 2750) {
        return tablica[getPaInt(pressure)][2];
    } else if (rpm < 3500) {
        return tablica[getPaInt(pressure)][3];
    } else {
        return tablica[getPaInt(pressure)][4];
    }
}

uint32_t Bobina::getPaInt(uint32_t pressure) {
    if (pressure < 20) {
        return 0;
    } else if (pressure < 28) {
        return 1;
    } else if (pressure < 35) {
        return 2;
    } else if (pressure < 45) {
        return 3;
    } else if (pressure < 55) {
        return 4;
    } else if (pressure < 65) {
        return 5;
    } else if (pressure < 75) {
        return 6;
    } else if (pressure < 85) {
        return 7;
    } else if (pressure < 95) {
        return 8;
    } else {
        return 9;
    }
}
