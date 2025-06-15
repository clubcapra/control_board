#include <AdapterCBRove.h>

uint32_t AdapterCBRoveClass::rgb2color(const RGBLed &led)
{
    return (led.r << 16) | (led.g << 8) | led.b;
}

AdapterCBRoveClass::AdapterCBRoveClass()
{
    rgb.setMode(staticMode);
}

void AdapterCBRoveClass::init()
{
    rgb.init();
    frontLED.init();
    backLED.init();
    debugLED.init();
    strobeLED.init();
}

bool AdapterCBRoveClass::setLEDFront(bool state)
{
    frontLED.set(state);
    return true;
}

bool AdapterCBRoveClass::setLEDBack(bool state)
{
    backLED.set(state);
    return true;
}

bool AdapterCBRoveClass::setLEDStrobe(bool state)
{
    strobeLED.set(state);
    return true;
}

bool AdapterCBRoveClass::getLEDFront()
{
    return frontLED.state();
}

bool AdapterCBRoveClass::getLEDBack()
{
    return backLED.state();
}

bool AdapterCBRoveClass::getLEDStrobe()
{
    return strobeLED.state();
}

bool AdapterCBRoveClass::setGPIO1(bool state)
{
    return false;
}

bool AdapterCBRoveClass::setGPIO2(bool state)
{
    return false;
}

bool AdapterCBRoveClass::setGPIO3(bool state)
{
    return false;
}

bool AdapterCBRoveClass::getGPIO1()
{
    return false;
}

bool AdapterCBRoveClass::getGPIO2()
{
    return false;
}

bool AdapterCBRoveClass::getGPIO3()
{
    return false;
}

void AdapterCBRoveClass::setRGBPattern(const RGBPattern& pattern)
{
    switch (pattern.mode)
    {
        case RGBModeType::RGB_MODE_STATIC:
            staticMode.setColor(rgb2color(pattern.color1));
            staticMode.setBreatheRate(pattern.breateRate);
            staticMode.setSpinRate(pattern.spinRate);
            rgb.setMode(staticMode);
            break;
        case RGBModeType::RGB_MODE_FADE2:
            fadeMode.set3Colors(false);
            fadeMode.setColor1(rgb2color(pattern.color1));
            fadeMode.setColor2(rgb2color(pattern.color2));
            fadeMode.setBreatheRate(pattern.breateRate);
            fadeMode.setSpinRate(pattern.spinRate);
            rgb.setMode(fadeMode);
            break;
        case RGBModeType::RGB_MODE_FADE3:
            fadeMode.set3Colors(true);
            fadeMode.setColor1(rgb2color(pattern.color1));
            fadeMode.setColor2(rgb2color(pattern.color2));
            fadeMode.setColor2(rgb2color(pattern.color3));
            fadeMode.setBreatheRate(pattern.breateRate);
            fadeMode.setSpinRate(pattern.spinRate);
            rgb.setMode(fadeMode);
            break;
        default:
            break;
    }
}

void AdapterCBRoveClass::update()
{
    rgb.update();
}

AdapterCBRoveClass AdapterCBRove = AdapterCBRoveClass();
