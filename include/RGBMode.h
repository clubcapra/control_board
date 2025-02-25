#ifndef RGB_MODE_H
#define RGB_MODE_H

#include "RGB.h"

class RGBMode {
    public:
    RGBMode() {}
    virtual void update(int index, RGB rgb) const = 0;
};

#endif /* "RGB_MODE_H" */
