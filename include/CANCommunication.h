#ifndef CAN_COMMUNICATION_H
#define CAN_COMMUNICATION_H

#include <Arduino.h>
#include "STM32_CAN.h"
#include <AdapterCBRove.h>
#include "api.h"

class CANCommunication {
public:
    CANCommunication(int baudRate = 500000, int timeoutMs = 1000, int canId = 1);
    
    void init();
    void receiveMessage();
    void checkWatchdog();
    void sendMessage(uint8_t* buff, size_t size);

private:
    int _baudRate;
    int _timeoutMs;
    int _canId;
    unsigned long _lastMsgTime;


    STM32_CAN _can;

    Buffer _buff{MAX_ENCODED_SIZE};
    CAN_message_t _msg;
};

#endif /* CAN_COMMUNICATION_H_ */
