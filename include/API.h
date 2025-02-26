#ifndef API_H
#define API_H

#include "RGBAdapter.h"
#include "Winch.h"
#include "LED.h"
#include "StatusEnums.h"
#include "RGBMode.h"
#include "RGBColor.h"

#include "RGBMode/FadeRGBMode.cpp"
#include "RGBMode/PatternRGBMode.cpp"
#include "RGBMode/StaticRGBMode.cpp"
#include "RGBMode/SwapRGBMode.cpp"
#include "RGBMode/RainbowRGBMode.cpp"

class API
{
public:
    API();

    void setRGB(RGBAdapter* rgb);
    void setWinch(Winch* winch);
    void setFrontLED(LED* frontLED);
    void setBackLED(LED* backLED);
    void setStrobeLED(LED* strobeLED);
    void setDebugLED(LED* debugLED);

    void onReceive(uint8_t data[], uint8_t length);
    void onTimeout();

    void setStatus(uint8_t status);

private:
    RGBAdapter* _rgb;
    Winch* _winch;
    LED* _frontLED;
    LED* _backLED;
    LED* _strobeLED;
    LED* _debugLED;

    FadeRGBMode _fadeMode;
    PatternRGBMode _patternMode;
    StaticRGBMode _staticMode;
    SwapRGBMode _swapMode;
    RainbowRGBMode _rainbowMode;
};

#endif /* API_H */
