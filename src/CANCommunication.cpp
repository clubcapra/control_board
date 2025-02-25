#include "CANCommunication.h"

CANCommunication::CANCommunication(int baudRate, int timeoutMs, int canId) 
    : _baudRate(baudRate), _timeoutMs(timeoutMs), _canId(canId), _can(CAN1, DEF) { // PA11, PA12
    _lastMsgTime = millis();
}

void CANCommunication::checkWatchdog() {
    if (_timeoutMs > 0 && millis() - _lastMsgTime > _timeoutMs) {
        _api->onTimeout();
        _lastMsgTime = millis();
    }
}

void CANCommunication::setAPI(API* api) {
    _api = api;
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
        if(_msg.id == _canId){
            if (_msg.flags.remote == false) {
                _api->onReceive(_msg.buf, _msg.len);
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
