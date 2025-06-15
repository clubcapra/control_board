#include "api.h"
#include "AdapterCBRove.h"

Int ping(Int i)
{
    return {i.i};
}

ULong hashCheck(Void _)
{
    return {API_HASH};
}

Bool_ setLEDFront(Bool_ state)
{
    AdapterCBRove.setLEDFront(state.b);
    return { true };
}

Bool_ setLEDBack(Bool_ state)
{
    AdapterCBRove.setLEDBack(state.b);
    return { true };
}

Bool_ setLEDStrobe(Bool_ state)
{
    AdapterCBRove.setLEDStrobe(state.b);
    return { true };
}

Bool_ getLEDFront(Void _)
{
    return { AdapterCBRove.getLEDFront() };
}

Bool_ getLEDBack(Void _)
{
    return { AdapterCBRove.getLEDBack() };
}

Bool_ getLEDStrobe(Void _)
{
    return { AdapterCBRove.getLEDStrobe() };
}

Bool_ getGPIO1(Void _)
{
    return { AdapterCBRove.getGPIO1() };
}

Bool_ setGPIO1(Bool_ state)
{
    AdapterCBRove.setGPIO1(state.b);
    return { true };
}

Bool_ getGPIO2(Void _)
{
    return { AdapterCBRove.getGPIO2() };
}

Bool_ setGPIO2(Bool_ state)
{
    AdapterCBRove.setGPIO2(state.b);
    return { true };
}

Bool_ getGPIO3(Void _)
{
    return { AdapterCBRove.getGPIO3() };
}

Bool_ setGPIO3(Bool_ state)
{
    AdapterCBRove.setGPIO3(state.b);
    return { true };
}

Bool_ setRGBPattern(RGBPattern pattern)
{
    // return { AdapterCBRove.setRGBLed(color) };
    return { false };
}