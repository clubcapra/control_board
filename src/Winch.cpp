#include "Winch.h"

Winch::Winch(uint8_t motorA, uint8_t motorB, uint8_t lock1, uint8_t lock2) : _motorA(motorA), _motorB(motorB), _lock1(lock1), _lock2(lock2) {}

void Winch::init() {
    pinMode(_motorA, OUTPUT);
    pinMode(_motorB, OUTPUT);
    digitalWrite(_motorA, LOW);
    digitalWrite(_motorB, LOW);
}

void Winch::motorControl(int percent) {
    percent = constrain(percent, -100, 100);  // Limit range to -100% to 100%
    int pwmValue = map(abs(percent), 0, 100, 0, 255); // Convert % to PWM (0-255)

    if (percent > 0) {
        analogWrite(_motorA, pwmValue);  // Forward
        digitalWrite(_motorB, LOW);
    } else if (percent < 0) {
        analogWrite(_motorB, pwmValue);  // Reverse
        digitalWrite(_motorA, LOW);
    } else {
        digitalWrite(_motorA, LOW);  // Stop
        digitalWrite(_motorB, LOW);
    }
}

void Winch::brake() {
    digitalWrite(_motorA, HIGH);
    digitalWrite(_motorB, HIGH);
}

void Winch::setLock1(bool lock) {
    digitalWrite(_lock1, lock);
}

void Winch::setLock2(bool lock) {
    digitalWrite(_lock2, lock);
}
