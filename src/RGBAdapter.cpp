#include "RGBAdapter.h"
#include "RGB.h"

RGBAdapter::RGBAdapter(uint16_t ledCount, uint8_t pin) : RGB(ledCount, pin) {}

void RGBAdapter::setMode(RGBMode& mode) {
    _mode = &mode;
}

void RGBAdapter::update() {
    // Assuming _mode is an enum or similar, handle the update logic here
    _mode->update(_index, this);
    indexAdd();
}

void RGBAdapter::indexAdd() {
    _index = (_index + 1) % 256;
}
