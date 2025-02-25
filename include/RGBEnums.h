#ifndef RGB_ENUMS_H
#define RGB_ENUMS_H

enum RGBColor {
    RED = 0xFF0000,
    GREEN = 0x00FF00,
    BLUE = 0x0000FF,
    YELLOW = 0xFFFF00,
    WHITE = 0xFFFFFF,
    OFF = 0x000000,
    ORANGE = 0xF81800,
    PINK = 0xFF1808,
    PURPLE = 0x8000FF,
};

enum RGBMode {
    RAINBOW = 0,
    PATTERN = 1,
    STATIC = 2,
    SWAP = 3,
    FADE = 4,
};

#endif /* RGB_ENUMS_H */
