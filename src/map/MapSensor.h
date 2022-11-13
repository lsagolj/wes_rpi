#pragma once
#include <Arduino.h>
#include <math.h>

class MapSensor {
public:
    MapSensor(uint8_t pin);
    uint32_t getRead() { return analogRead(PIN_MAP); }
    double getVoltage() { return (double)getRead() * 5.f / 1023.f; }
    uint32_t getPressure() { return turnVoltageToPressure(getVoltage()); }
private:
    uint32_t turnVoltageToPressure(double voltage) { return round(21.25 * voltage + 4.375); }
    uint8_t PIN_MAP;
};