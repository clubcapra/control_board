#include "RGBAdapter.h"
#include "Winch.h"
#include "LED.h"
#include "CANCommunication.h"
#include "API.h"

RGBAdapter rgb(27, PA9);  // Create RGB object with 12 LEDs on pin PB12
Winch winch(PA3, PA4, PA10, PA2);  // Create Winch object with motor control pins
LED frontLED(PC4);  // Create LED object for front LED
LED backLED(PB4);  // Create LED object for back LED
LED debugLED(PB6);  // Create LED object for debug LED
LED strobeLED(PA15);  // Create LED object for strobe LED
CANCommunication can(250000, 0, 1);  // baud rate, timeout, CAN ID (pa11, pa12 used for CAN)
API api;

void setup() {
    rgb.init(); // Initialize all pixels to 'off'
    winch.init();  // Initialize motor control
    frontLED.init();  // Initialize front LED
    backLED.init();  // Initialize back LED
    debugLED.init();  // Initialize debug LED
    strobeLED.init();  // Initialize strobe LED

    api.setRGB(&rgb);
    api.setWinch(&winch);
    api.setFrontLED(&frontLED);
    api.setBackLED(&backLED);
    api.setStrobeLED(&strobeLED);
    api.setDebugLED(&debugLED);

    api.setStatus(STATUS_OK);

    can.init();
    can.setAPI(&api);
}

void loop() {
    can.receiveMessage();  // Check for incoming CAN messages
    can.checkWatchdog();  // Check for watchdog timeout
    rgb.update();  // Update RGB LEDs based on current mode
}
