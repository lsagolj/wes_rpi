#include "MapSensor.h"

MapSensor::MapSensor(uint8_t pin) :
        PIN_MAP(pin) {

    pinMode(pin, INPUT);
}