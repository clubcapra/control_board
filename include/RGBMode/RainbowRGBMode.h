#include "RGBMode.h"

class RainbowRGBMode : public RGBMode {
protected:
    void updateImpl(int index, RGBController* rgb) override {
        for (int i = 0; i < rgb->numPixels(); i++) {
            rgb->setColor(i, wheel(((i + index) * 256 * 3 / rgb->numPixels()) & 255));
        }
        rgb->show();
    }
public:
    RainbowRGBMode() {}

private:
    uint32_t wheel(byte WheelPos) const {
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
        return (r << 16) | (g << 8) | b;
    }
};
