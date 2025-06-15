#pragma once

#include <Arduino.h>

class GPIO 
{
private:
    size_t mPin;
    bool mState = false;

public:
    GPIO(size_t pin);
    void init();
    bool state();
    void set(bool _state);
    void on();
    void off();
};