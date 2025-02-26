#include "API.h"

#define FRONT_LED_BIT 1
#define BACK_LED_BIT 1 << 1
#define DEBUG_LED_BIT 1 << 2
#define WINCH_BRAKE_BIT 1 << 3

API::API() {}

void API::onReceive(uint8_t data[], uint8_t length) {
    if (length < 2) return;
    
    // Update LEDs
    if (data[0] & FRONT_LED_BIT) {
        _frontLED->on();
    } else {
        _frontLED->off();
    }
    if (data[0] & BACK_LED_BIT) {
        _backLED->on();
    } else {
        _backLED->off();
    }
    if (data[0] & DEBUG_LED_BIT) {
        _debugLED->on();
    } else {
        _debugLED->off();
    }
    if (data[0] & WINCH_BRAKE_BIT) {
        _winch->brake();
    } else {
        // Extract winch position (-128 to 127), unsigned to signed
        int winchPercent = (int8_t)data[1];
        _winch->motorControl(winchPercent);
    }

    int status = data[0] >> 4; // Extract status bits (0-15)
    setStatus(status);
}

void API::setStatus(uint8_t status) {
    switch (status)
    {
    case STATUS_OK:
        _staticMode.setColor(GREEN);
        _rgb->setMode(_staticMode);
        break;
    case STATUS_RUNNING: // WARNING
        _patternMode.setPattern(ORANGE, OFF);
        _rgb->setMode(_patternMode);
        break;
    case STATUS_UNKNOWN_ERROR: // ERROR
        _staticMode.setColor(RED);
        _rgb->setMode(_staticMode);
        break;
    case STATUS_TIMEOUT:
        _patternMode.setPattern(YELLOW, GREEN);
        _rgb->setMode(_patternMode);
        break;
    case STATUS_BATTERY_LOW: // Battery Low
        _swapMode.setPattern(RED, OFF);
        _rgb->setMode(_swapMode);
        break;
    case STATUS_LOST_COMM: // Lost Communication
        _fadeMode.setColor(PURPLE);
        _rgb->setMode(_fadeMode);
        break;
    case STATUS_POLICE: // Police
        _patternMode.setPattern(RED, BLUE);
        _rgb->setMode(_patternMode);
        break;
    case STATUS_RAINBOW: // Rainbow
        _rgb->setMode(_rainbowMode);
        break;
    default:
        break;
    }
}

void API::onTimeout() {
    _winch->brake();
    setStatus(STATUS_TIMEOUT);
}

void API::setRGB(RGBAdapter* rgb) {
    _rgb = rgb;

    _fadeMode = FadeRGBMode();
    _patternMode = PatternRGBMode();
    _staticMode = StaticRGBMode();
    _swapMode = SwapRGBMode();
    _rainbowMode = RainbowRGBMode();
}

void API::setWinch(Winch* winch) {
    _winch = winch;
}

void API::setFrontLED(LED* frontLED) {
    _frontLED = frontLED;
}

void API::setBackLED(LED* backLED) {
    _backLED = backLED;
}

void API::setStrobeLED(LED* strobeLED) {
    _strobeLED = strobeLED;
}

void API::setDebugLED(LED* debugLED) {
    _debugLED = debugLED;
}
