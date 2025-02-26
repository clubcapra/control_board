#ifndef RGB_ADAPTER_H
#define RGB_ADAPTER_H

#include "RGB.h"
#include "RGBMode.h"

class RGBAdapter: public RGB {
    private:
    /**
     * @brief Increments the index for the effect
     */
    void indexAdd();

    
    uint32_t RGBtoHex(uint8_t red, uint8_t green, uint8_t blue);

    int _index = 0;
    RGBMode* _mode;

    public:
    /**
     * @brief Constructor for RGBAdapter
     * @param ledCount Number of LEDs in the strip
     * @param pin Pin where the strip is connected
     */
    RGBAdapter(uint16_t ledCount, uint8_t pin);

    /**
     * @brief Sets the mode for the LEDs
     * @param mode RGBMode enum value
     */
    void setMode(RGBMode& mode);

    /**
     * @brief Updates the LEDs based on the current mode
     */
    void update();
};

#endif /* RGB_ADAPTER_H */
