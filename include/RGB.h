#ifndef RGB_H
#define RGB_H

#include <Adafruit_NeoPixel.h>

class RGB {
private:
    Adafruit_NeoPixel _strip;
    
public:
    /**
     * @brief Constructor for RGB LED Strip
     * @param ledCount Number of LEDs in the strip
     * @param pin Pin where the strip is connected
     */
    RGB(uint16_t ledCount, uint8_t pin);

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
     * @brief Updates the LED strip
     */
    void show();

    /**
     * @brief Returns the number of LEDs in the strip
     * @return Number of LEDs
     */
    uint16_t numPixels();
};

#endif
