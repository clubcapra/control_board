#ifndef ADAPTER_CB_ROVE_H
#define ADAPTER_CB_ROVE_H

#include <Arduino.h>
#include <GPIO.h>
#include <RGBAdapter.h>
#include <api.h>
#include "RGBMode/FadeRGBMode.h"
#include "RGBMode/RainbowRGBMode.h"
#include "RGBMode/StaticRGBMode.h"

class AdapterCBRoveClass {
private:
    RGBAdapter rgb{27, PA9};  // Create RGBController object with 12 LEDs on pin PA9
    GPIO frontLED{PC4};  // Create LED object for front LED
    GPIO backLED{PB4};  // Create LED object for back LED
    GPIO debugLED{PB6};  // Create LED object for debug LED
    GPIO strobeLED{PA15};  // Create LED object for strobe LED

    FadeRGBMode fadeMode;
    RainbowRGBMode rainbowMode;
    StaticRGBMode staticMode;

    uint32_t rgb2color(const RGBLed& led);
public:
    // Constructor
    AdapterCBRoveClass();

    // Destructor
    // ~AdapterCBRoveClass();

    void init();

    bool setLEDFront(bool state);
    bool setLEDBack(bool state);
    bool setLEDStrobe(bool state);
    
    bool getLEDFront();
    bool getLEDBack();
    bool getLEDStrobe();

    bool setGPIO1(bool state);
    bool setGPIO2(bool state);
    bool setGPIO3(bool state);

    bool getGPIO1();
    bool getGPIO2();
    bool getGPIO3();

    void setRGBPattern(const RGBPattern& pattern);

    void update();
};

extern AdapterCBRoveClass AdapterCBRove;

#endif // ADAPTER_CB_ROVE_H