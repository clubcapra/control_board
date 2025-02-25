#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED {
private:
    uint8_t _pinNum;  // Store pin number

public:
    /**
     * @brief Construct an LED object
     * @param pinNum The pin connected to the LED
     */
    LED(uint8_t pinNum);

    /**
     * @brief Initialize the LED
     */
    void init();

    /**
     * @brief Turn on the LED
     * @return Reference to the LED object
     */
    LED& on();

    /**
     * @brief Turn off the LED
     * @return Reference to the LED object
     */
    LED& off();
};

#endif /* LED_H_ */
