#include "RGBAdapter.h"
#include "CANCommunication.h"
#include "GPIO.h"

CANCommunication can(500000, 0, 1);  // baud rate, timeout, CAN ID (pa11, pa12 used for CAN)

void onSend(uint8_t* buff, size_t length)
{
    can.sendMessage(buff, length);
}


void setup() {
    CommandManager.setCommands(commands, COMMANDS_COUNT);
    CommandManager.setSendCB(&onSend);

    can.init();
}

void loop() {
    can.receiveMessage();  // Check for incoming CAN messages
    can.checkWatchdog();  // Check for watchdog timeout
}
