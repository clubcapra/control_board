#include "RGBMode.h"

class SwapRGBMode : public RGBMode {
    private:
    uint32_t _color1;
    uint32_t _color2;

    public:
    SwapRGBMode() {}

    void update(int index, RGB* rgb) const override {
        rgb->setAllBrightness(255);

        uint32_t color = (index / 8 % 2 == 0)? _color1 : _color2;
        rgb->setAllColor(color);
        rgb->show();
    }

    void setPattern(uint32_t color1, uint32_t color2) {
        _color1 = color1;
        _color2 = color2;
    }
};
