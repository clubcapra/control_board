#ifndef API_H
#define API_H

#include "RGBAdapter.h"
#include "Winch.h"
#include "LED.h"
#include "StatusEnums.h"

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

    void onReceive(u_int8_t data[], u_int8_t length);
    void onTimeout();

    void setStatus(u_int8_t status);

private:
    RGBAdapter* _rgb;
    Winch* _winch;
    LED* _frontLED;
    LED* _backLED;
    LED* _strobeLED;
    LED* _debugLED;
};

#endif /* API_H */
