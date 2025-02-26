#include "RGBMode.h"

class PatternRGBMode : public RGBMode {
    private:
    uint32_t _color1;
    uint32_t _color2;

    public:
    PatternRGBMode() {}

    void update(int index, RGB* rgb) const override {
        rgb->setAllBrightness(255);

        if (index / 8 % 2 == 0)
        {
            for (int i = 0; i < rgb->numPixels(); i++) {
                if (i % 2 == 0) {
                    rgb->setColor(i, _color1);
                } else {
                    rgb->setColor(i, _color2);
                }
            }
        } else {
            for (int i = 0; i < rgb->numPixels(); i++) {
                if (i % 2 == 0) {
                    rgb->setColor(i, _color2);
                } else {
                    rgb->setColor(i, _color1);
                }
            }
        }
        rgb->show();
    }

    void setPattern(uint32_t color1, uint32_t color2) {
        _color1 = color1;
        _color2 = color2;
    }
};
