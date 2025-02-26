#include "RGBMode.h"

class FadeRGBMode : public RGBMode {
    private:
    uint32_t _color;

    public:
    FadeRGBMode() {}

    void update(int index, RGB* rgb) const override {
        int brightness = abs((index * 2) - 256) + 8;
        brightness = (brightness > 255)? 255 : brightness;
        rgb->setAllColor(_color);
        rgb->setAllBrightness(brightness);
        rgb->show();
    }

    void setColor(uint32_t color) {
        _color = color;
    }
};
