#ifndef RGB_ADAPTER_H
#define RGB_ADAPTER_H

#include "RGB.h"
#include "RGBEnums.h"

class RGBAdapter {
    private:
    /**
     * @brief Generates a color for the rainbow effect
     * @param WheelPos Position in the color wheel (0-255)
     * @return 32-bit color value
     */
    uint32_t wheel(byte WheelPos);

    /**
     * @brief Increments the index for the effect
     */
    void indexAdd();

    
    uint32_t RGBtoHex(uint8_t red, uint8_t green, uint8_t blue);

    int _index = 0;

    uint32_t _color1 = 0;
    uint32_t _color2 = 0;
    RGBMode _mode = RGBMode::STATIC;

    RGB _rgb;

    public:
    /**
     * @brief Constructor for RGBAdapter
     * @param ledCount Number of LEDs in the strip
     * @param pin Pin where the strip is connected
     */
    RGBAdapter(uint16_t ledCount, uint8_t pin);

    /**
     * @brief Initializes the LED strip
     */
    void init();

    /**
     * @brief Sets a specific LED color
     * @param pixel Index of the LED
     * @param red Red component (0-255)
     * @param green Green component (0-255)
     * @param blue Blue component (0-255)
     */
    void setColor(int pixel, uint8_t red, uint8_t green, uint8_t blue);

    /**
     * @brief Sets a specific LED color
     * @param pixel Index of the LED
     * @param color 32-bit color value
     */
    void setColor(int pixel, uint32_t color);

    /**
     * @brief Sets all LEDs to the same color
     * @param red Red component (0-255)
     * @param green Green component (0-255)
     * @param blue Blue component (0-255)
     */
    void setAllColor(uint8_t red, uint8_t green, uint8_t blue);

    /**
     * @brief Sets all LEDs to the same color
     * @param color 32-bit color value
     */
    void setAllColor(uint32_t color);

    /**
     * @brief Sets brightness for all LEDs
     * @param brightness Brightness level (0-255)
     */
    void setAllBrightness(uint8_t brightness);

    /**
     * @brief Shifts a rainbow effect across the LEDs
     */
    void rainbowShift();

    /**
     * @brief Sets a pattern across the LEDs
     * @param red1 Red component for the first color (0-255)
     * @param green1 Green component for the first color (0-255)
     * @param blue1 Blue component for the first color (0-255)
     * @param red2 Red component for the second color (0-255)
     * @param green2 Green component for the second color (0-255)
     * @param blue2 Blue component for the second color (0-255)
     */
    void setPatern(uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2);

    /**
     * @brief Sets a pattern across the LEDs
     * @param color1 32-bit color value for the first color
     * @param color2 32-bit color value for the second color
     */
    void setPatern(uint32_t color1, uint32_t color2);

    /**
     * @brief Shifts a pattern across the LEDs
     */
    void paternShift();

    /**
     * @brief Swaps the color pattern
     */
    void swapShift();

    void fadeShift();

    /**
     * @brief Sets the mode for the LEDs
     * @param mode RGBMode enum value
     */
    void setMode(RGBMode mode);

    /**
     * @brief Updates the LEDs based on the current mode
     */
    void update();
};

#endif /* RGB_ADAPTER_H */
