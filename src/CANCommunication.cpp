#include "CANCommunication.h"
#include "capra_comm.h"
#include "api.h"

CANCommunication::CANCommunication(int baudRate, int timeoutMs, int canId) 
    : _baudRate(baudRate), _timeoutMs(timeoutMs), _canId(canId), _can(CAN1, DEF) { // PA11, PA12
    _lastMsgTime = millis();
}

void CANCommunication::checkWatchdog() {
    if (_timeoutMs > 0 && millis() - _lastMsgTime > _timeoutMs) {
        _lastMsgTime = millis();
    }
}

void CANCommunication::sendMessage(uint8_t *buff, size_t size)
{
    CAN_message_t msg = CAN_message_t();
    for (size_t i = 0, ii = 0; i < size; i+=8, ++ii)
    {
        auto len = (size - i) > 8 ? 8 : (size - i);
        memcpy(msg.buf, buff + i, len);
        msg.id = _canId;
        msg.len = len;
    }
    _can.write(msg);
}

void CANCommunication::receiveMessage()  // Read data from CAN bus and print out the messages to serial bus. Note that only message ID's that pass filters are read.
{
    if (_can.read(_msg) ) {
        Serial.print("Channel:");
        Serial.print(_msg.bus);
        if (_msg.flags.extended == false) {
            Serial.print(" Standard ID:");
        }
        else {
            Serial.print(" Extended ID:");
        }
        Serial.println(_msg.id);
        if(_msg.id == _canId){
            if (_msg.flags.remote == false) {
                _buff.write(_msg.buf, _msg.len);
                switch (CommandManager.status())
                {
                    case _CommandManager::CMD_ID_OUT_OF_RANGE: // Command id out of range
                        // This can either be from a transmission issue or from an API version mismatch
                        while (_buff.available()) _buff.read();
                        break;
                    case _CommandManager::CALLBACK_NULL: // The sendCB callback is null
                        // You forgot to set the callback: CommandManager.setSendCB(&sendCallback)
                        Serial.println("Set the callback");
                        break;
                    case _CommandManager::PARAM_SIZE_MISMATCH: // Not enough data to decode parameter
                        // This can simply be because the message is incomplete
                        break;
                    case _CommandManager::PEEK_ID_ERROR:
                    case _CommandManager::READ_ID_ERROR:
                    case _CommandManager::READ_PARAM_ERROR:
                        // These are problems that occur while reading the buffer
                        while (_buff.available()) _buff.read();
                        break;
                    default:
                        break;
                }
            } else {
                Serial.println(" Data: REMOTE REQUEST FRAME");
            }
            _lastMsgTime = millis();
        }
    }
}

void CANCommunication::init(){
    Serial.begin(115200);
    _can.begin();
    _can.setBaudRate(_baudRate);
    
}



