#include <GPIO.h>

GPIO::GPIO(size_t pin) : mPin(pin) {}

void GPIO::init()
{
    pinMode(mPin, OUTPUT);
    set(false);
}

bool GPIO::state()
{
    return mState;
}

void GPIO::set(bool _state)
{
    mState = _state;
    digitalWrite(mPin, _state);
}

void GPIO::on()
{
    set(true);
}

void GPIO::off()
{
    set(false);
}
