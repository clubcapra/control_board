#include "RGBAdapter.h"
#include "CANCommunication.h"
#include "GPIO.h"

CANCommunication can(500000, 0, 1);  // baud rate, timeout, CAN ID (pa11, pa12 used for CAN)

GPIO dbgLed = {PB6};

void onSend(uint8_t* buff, size_t length)
{
    can.sendMessage(buff, length);
}

HardwareSerial Serial1(PA8, PA9);
void setup() {
    dbgLed.init();
    dbgLed.on();
    Serial.begin(115200);
    while (!Serial);
    Serial.println("Started");

    CommandManager.setCommands(commands, COMMANDS_COUNT);
    CommandManager.setSendCB(&onSend);

    can.init();
}

void loop() {
    can.receiveMessage();  // Check for incoming CAN messages
    can.checkWatchdog();  // Check for watchdog timeout
    AdapterCBRove.update();
}
