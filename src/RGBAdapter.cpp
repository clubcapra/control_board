#include "RGBAdapter.h"
#include "RGB.h"

RGBAdapter::RGBAdapter(uint16_t ledCount, uint8_t pin) : _rgb(ledCount, pin) {}

void RGBAdapter::init() {
    _rgb.init();
}

void RGBAdapter::setColor(int pixel, uint8_t red, uint8_t green, uint8_t blue) {
    _rgb.setColor(pixel, red, green, blue);
    _rgb.show();
}

void RGBAdapter::setColor(int pixel, uint32_t color) {
    _rgb.setColor(pixel, color);
    _rgb.show();
}

void RGBAdapter::setAllColor(uint8_t red, uint8_t green, uint8_t blue) {
    _rgb.setAllColor(red, green, blue);
    _rgb.show();
}

void RGBAdapter::setAllColor(uint32_t color) {
    _rgb.setAllColor(color);
    _rgb.show();
}

void RGBAdapter::setAllBrightness(uint8_t brightness) {
    _rgb.setAllBrightness(brightness);
    _rgb.show();
}

void RGBAdapter::rainbowShift() {
    for (int i = 0; i < _rgb.numPixels(); i++) {
        _rgb.setColor(i, wheel(((i + _index) * 256 * 3 / _rgb.numPixels()) & 255));
    }
    _rgb.show();

    indexAdd();
}

uint32_t RGBAdapter::wheel(byte WheelPos) {
    uint8_t r, g, b;
    int index = (WheelPos) % 256;

    if (index < 85) {
        r = 255 - index * 3;
        g = index * 3;
        b = 0;
    } else if (index < 170) {
        index -= 85;
        r = 0;
        g = 255 - index * 3;
        b = index * 3;
    } else {
        index -= 170;
        r = index * 3;
        g = 0;
        b = 255 - index * 3;
    }
    return RGBtoHex(r, g, b);
}

void RGBAdapter::setPatern(uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2) {
    setPatern(RGBtoHex(red1, green1, blue1), RGBtoHex(red2, green2, blue2));
}

void RGBAdapter::setPatern(uint32_t color1, uint32_t color2) {
    _color1 = color1;
    _color2 = color2;
}

void RGBAdapter::paternShift() {
    if (_index / 8 % 2 == 0)
    {
        for (int i = 0; i < _rgb.numPixels(); i++) {
            if (i % 2 == 0) {
                _rgb.setColor(i, _color1);
            } else {
                _rgb.setColor(i, _color2);
            }
        }
    } else {
        for (int i = 0; i < _rgb.numPixels(); i++) {
            if (i % 2 == 0) {
                _rgb.setColor(i, _color2);
            } else {
                _rgb.setColor(i, _color1);
            }
        }
    }
    _rgb.show();

    indexAdd();
}

void RGBAdapter::swapShift() {
    uint32_t color = (_index / 8 % 2 == 0)? _color1 : _color2;
    setAllColor(color);

    indexAdd();
}

void RGBAdapter::fadeShift() {
    int brightness = abs((_index * 8) - 256) + 8;
    brightness = (brightness > 255)? 255 : brightness;
    setAllBrightness(brightness);
    _rgb.show();

    indexAdd();
}

void RGBAdapter::setMode(RGBMode mode) {
    if (mode != _mode && _mode == FADE) {
        setAllBrightness(255);
    }

    _mode = mode;
}

void RGBAdapter::update() {
    switch (_mode) {
        case RGBMode::RAINBOW:
            rainbowShift();
            break;
        case RGBMode::PATTERN:
            paternShift();
            break;
        case RGBMode::SWAP:
            swapShift();
            break;
        case RGBMode::FADE:
            fadeShift();
            break;
        default:
            break;
    }
}

void RGBAdapter::indexAdd() {
    _index = (_index + 1) % 64;
}

uint32_t RGBAdapter::RGBtoHex(uint8_t red, uint8_t green, uint8_t blue) {
    return (red << 16) | (green << 8) | blue;
}
