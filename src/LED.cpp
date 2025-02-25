#include "LED.h"

LED::LED(uint8_t pinNum) : _pinNum(pinNum) {}

void LED::init() {
    pinMode(_pinNum, OUTPUT);
    digitalWrite(_pinNum, LOW); // Ensure LED starts off
}

LED& LED::on() {
    digitalWrite(_pinNum, HIGH);
    return *this;
}

LED& LED::off() {
    digitalWrite(_pinNum, LOW);
    return *this;
}
