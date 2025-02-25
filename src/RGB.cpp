#include "RGB.h"

RGB::RGB(uint16_t ledCount, uint8_t pin) : _strip(ledCount, pin, NEO_BRG + NEO_KHZ800) {}

void RGB::init() {
    _strip.begin();
}

void RGB::setColor(int pixel, uint8_t red, uint8_t green, uint8_t blue) {
    setColor(pixel, _strip.Color(red, green, blue));
}

void RGB::setColor(int pixel, uint32_t color) {
    if (pixel >= 0 && pixel < _strip.numPixels()) {
        _strip.setPixelColor(pixel, color);
        _strip.show();
    }
}

void RGB::setAllColor(uint8_t red, uint8_t green, uint8_t blue) {
    setAllColor(_strip.Color(red, green, blue));
}

void RGB::setAllColor(uint32_t color) {
    for (int i = 0; i < _strip.numPixels(); i++) {
        _strip.setPixelColor(i, color);
    }
    _strip.show();
}

void RGB::setAllBrightness(uint8_t brightness) {
    _strip.setBrightness(brightness);
    _strip.show();
}

void RGB::show() {
    _strip.show();
}

uint16_t RGB::numPixels(){
    return _strip.numPixels();
}
