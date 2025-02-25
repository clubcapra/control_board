# Control Board

## Control Message Structure:

In the context of the provided `API.cpp` code, the control messages follow a specific structure to manage various components:

1. **Byte 0**: Control flags for LEDs and winch brake.
   - Bit 0: Front LED (1 = ON, 0 = OFF)
   - Bit 1: Back LED (1 = ON, 0 = OFF)
   - Bit 2: Debug LED (1 = ON, 0 = OFF)
   - Bit 3: Winch brake (1 = BRAKE, 0 = CONTROL)
   - Bits 4-7: Status code for RGB LED (0 to 15)
2. **Byte 1**: Winch control data.
   - Bits 0-7: Winch percent (-100 to 100, signed value)

## Status dictionnary

| Code | Status             | Pattern | Color        |
| ---: | :----------------- | ------- | ------------ |
|    0 | OK                 | Static  | Green        |
|    1 | Running (Warning)  | Pattern | Orange/Off   |
|    2 | Unknown Error      | Static  | Red          |
|    3 | Timeout            | Pattern | Yellow/Green |
|    4 | Battery Low        | Swap    | Red/Off      |
|    5 | Lost Communication | Fade    | Purple       |
|   14 | Police             | Pattern | Red/Blue     |
|   15 | Rainbow            | Rainbow | -            |
