#pragma once
#include "RGBMode.h"

class FadeRGBMode : public RGBMode {
private:
    uint32_t _color1 = 0;
    uint32_t _color2 = 0;
    uint32_t _color3 = 0;
    bool _3colors = false;

    // Helper: interpolate between two RGB colors
    uint32_t lerpColor(uint32_t c1, uint32_t c2, float t) {
        uint8_t r1 = (c1 >> 16) & 0xFF;
        uint8_t g1 = (c1 >> 8) & 0xFF;
        uint8_t b1 = c1 & 0xFF;

        uint8_t r2 = (c2 >> 16) & 0xFF;
        uint8_t g2 = (c2 >> 8) & 0xFF;
        uint8_t b2 = c2 & 0xFF;

        uint8_t r = r1 + (r2 - r1) * t;
        uint8_t g = g1 + (g2 - g1) * t;
        uint8_t b = b1 + (b2 - b1) * t;

        return (r << 16) | (g << 8) | b;
    }

protected:
    void updateImpl(int /*index*/, RGBController* rgb) override {
        int count = rgb->numPixels();
        if (count <= 0) return;

        int segments = _3colors ? 3 : 2;
        int segmentLength = count / segments;

        for (int i = 0; i < count; ++i) {
            float position = (float)i / count;

            uint32_t cA, cB;
            float t;

            if (_3colors) {
                if (i < segmentLength) {
                    cA = _color1;
                    cB = _color2;
                    t = (float)i / segmentLength;
                } else if (i < 2 * segmentLength) {
                    cA = _color2;
                    cB = _color3;
                    t = (float)(i - segmentLength) / segmentLength;
                } else {
                    cA = _color3;
                    cB = _color1;
                    t = (float)(i - 2 * segmentLength) / (count - 2 * segmentLength);
                }
            } else {
                if (i < segmentLength) {
                    cA = _color1;
                    cB = _color2;
                    t = (float)i / segmentLength;
                } else {
                    cA = _color2;
                    cB = _color1;
                    t = (float)(i - segmentLength) / (count - segmentLength);
                }
            }

            uint32_t color = lerpColor(cA, cB, t);
            rgb->setColor(i, color);
        }

        rgb->show();
    }

public:
    FadeRGBMode() {}

    void setColor1(uint32_t color) {
        _color1 = color;
    }

    void setColor2(uint32_t color) {
        _color2 = color;
    }

    void setColor3(uint32_t color) {
        _color3 = color;
    }

    void set3Colors(bool value) {
        _3colors = value;
    }
};
