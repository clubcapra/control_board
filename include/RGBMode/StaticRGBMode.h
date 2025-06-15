#pragma once
#include "RGBMode.h"

class StaticRGBMode : public RGBMode {
protected:
    void updateImpl(int index, RGBController* rgb) override{
        rgb->setAllColor(_color);
        rgb->show();
    }
public:
    StaticRGBMode() {}

    void setColor(uint32_t color) {
        _color = color;
    }

private:
    uint32_t _color;
};