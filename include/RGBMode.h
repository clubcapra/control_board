#ifndef RGB_MODE_H
#define RGB_MODE_H

#include "RGBController.h"

class RGBMode
{
private:
    uint8_t mSpinRate = 0;
    uint8_t mBreatheRate = 0;
private:
    // Convert rate to period in milliseconds (10s/rate)
    uint32_t period(uint8_t rate)
    {
        return (rate == 0) ? 0 : 10000 / (uint32_t)rate;
    }

    // Determine spin starting index based on time
    int spinStartIndex(int count)
    {
        if (mSpinRate == 0) return 0;
        auto p = period(mSpinRate);
        auto progress = millis() % p;
        return progress * count / p;
    }

    // Determine current intensity in breathing mode
    uint8_t breatheIntensity()
    {
        if (mBreatheRate == 0) return 255;
        auto p = period(mBreatheRate);
        auto progress = millis() % p;
        auto r = 512 * progress / p;
        if (r >= 255)
            return 511 - r;
        return r;
    }
protected:
    virtual void updateImpl(int index, RGBController* rgb) = 0;
    uint32_t scale(uint32_t color, uint8_t brightness)
    {
        // Extract R, G, B components
        uint8_t r = (color >> 16) & 0xFF;
        uint8_t g = (color >> 8) & 0xFF;
        uint8_t b = color & 0xFF;

        // Scale components by brightness (0-255)
        r = (r * brightness) / 255;
        g = (g * brightness) / 255;
        b = (b * brightness) / 255;

        // Recombine into a 0x00RRGGBB format
        return (r << 16) | (g << 8) | b;
    }
public:
    RGBMode() {}
    void setSpinRate(uint8_t rate) { mSpinRate = rate; }
    void setBreatheRate(uint8_t rate) { mBreatheRate = rate; }
    void update(int index, RGBController* rgb)
    {
        auto actualIndex = (spinStartIndex(rgb->numPixels()) + index) % rgb->numPixels();
        rgb->setAllBrightness(breatheIntensity());
        this->updateImpl(actualIndex, rgb);
    }
};

#endif /* "RGB_MODE_H" */
