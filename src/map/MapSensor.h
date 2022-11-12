#pragma once
#include <Arduino.h>
#include <math.h>

class MapSensor {
public:
    MapSensor(uint8_t pin);
    int getRead() { return analogRead(PIN_MAP); }
    float getVoltage() { return (float)getRead() * 5.f / 1023.f; }
    int getPressure() { return turnVoltageToPressure(getVoltage()); }
private:
    int turnVoltageToPressure(float voltage) { return round(21.25 * voltage + 4.375); }
    uint8_t PIN_MAP;
};