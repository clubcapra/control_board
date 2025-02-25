#ifndef CAN_COMMUNICATION_H
#define CAN_COMMUNICATION_H

#include <Arduino.h>
#include "STM32_CAN.h"

#include "API.h"

class CANCommunication {
public:
    CANCommunication(int baudRate = 500000, int timeoutMs = 1000, int canId = 1);
    
    void init();
    void receiveMessage();
    void checkWatchdog();

    void setAPI(API* api);

private:
    int _baudRate;
    int _timeoutMs;
    int _canId;
    unsigned long _lastMsgTime;

    API *_api;

    STM32_CAN _can;

    CAN_message_t _msg;
};

#endif /* CAN_COMMUNICATION_H_ */
