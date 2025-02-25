#include "RGBMode.h"

class StaticRGBMode : public RGBMode {
    public:
    StaticRGBMode() {}

    void update(int index, RGB rgb) const override{
        rgb.setAllBrightness(255);
        rgb.setAllColor(_color);
        rgb.show();
    }

    void setColor(uint32_t color) {
        _color = color;
    }

    private:
    uint32_t _color;
};
