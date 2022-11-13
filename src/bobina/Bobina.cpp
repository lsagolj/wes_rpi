#include "Bobina.h"

uint32_t tablica[5][10] = {
    {13, 13, 13, 13, 13, 13, 14, 14, 15, 18},
    {18, 18, 19, 19, 19, 20, 20, 21, 23, 25},
    {20, 21, 22, 23, 24, 24, 25, 28, 30, 34},
    {25, 28, 30, 32, 33, 35, 36, 38, 40, 38},
    {25, 28, 30, 32, 33, 35, 36, 38, 40, 42}
};


Bobina::Bobina() {

}

uint32_t Bobina::getAngle(uint32_t pressure, uint32_t rpm) {
    if (rpm < 1200) {
        return 10;
    } else if (rpm < 1600) {
        return tablica[0][getPaInt(pressure)];
    } else if (rpm < 2150) {
        return tablica[1][getPaInt(pressure)];
    } else if (rpm < 2750) {
        return tablica[2][getPaInt(pressure)];
    } else if (rpm < 3500) {
        return tablica[3][getPaInt(pressure)];
    } else if (rpm < 5000) {
        return tablica[4][getPaInt(pressure)];
    } else{
        return tablica[5][getPaInt(pressure)];
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