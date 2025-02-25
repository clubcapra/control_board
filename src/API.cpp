#include "API.h"

API::API() {}

void API::onReceive(u_int8_t data[], u_int8_t length) {
    if (length < 2) return;
    
    // Update LEDs
    if (data[0] >> 0 & 1) {
        _frontLED->on();
    } else {
        _frontLED->off();
    }
    if (data[0] >> 1 & 1) {
        _backLED->on();
    } else {
        _backLED->off();
    }
    if (data[0] >> 2 & 1) {
        _debugLED->on();
    } else {
        _debugLED->off();
    }
    if (data[0] >> 3 & 1) {
        _winch->brake();
    } else {
        // Extract winch position (-128 to 127), unsigned to signed
        int winchPercent = ((data[1] >> 7 & 1) ? data[1] - 0xff - 1 : data[1]);
        _winch->motorControl(winchPercent);
    }

    int status = data[0] >> 4; // Extract status bits (0-15)
    setStatus(status);
}

void API::setStatus(u_int8_t status) {
    switch (status)
    {
    case STATUS_OK:
        _rgb->setAllColor(GREEN);
        _rgb->setMode(RGBMode::STATIC);
        break;
    case STATUS_RUNNING: // WARNING
        _rgb->setPatern(ORANGE, OFF);
        _rgb->setMode(RGBMode::PATTERN);
        break;
    case STATUS_UNKNOWN_ERROR: // ERROR
        _rgb->setAllColor(RED);
        _rgb->setMode(RGBMode::STATIC);
        break;
    case STATUS_TIMEOUT:
        _rgb->setPatern(YELLOW, GREEN);
        _rgb->setMode(RGBMode::PATTERN);
        break;
    case STATUS_BATTERY_LOW: // Battery Low
        _rgb->setPatern(RED, OFF);
        _rgb->setMode(RGBMode::SWAP);
        break;
    case STATUS_LOST_COMM: // Lost Communication
        _rgb->setAllColor(PURPLE);
        _rgb->setMode(RGBMode::FADE);
        break;
    case STATUS_POLICE: // Police
        _rgb->setPatern(RED, BLUE);
        _rgb->setMode(RGBMode::PATTERN);
        break;
    case STATUS_RAINBOW: // Rainbow
        _rgb->setMode(RGBMode::RAINBOW);
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
