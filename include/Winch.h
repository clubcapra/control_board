#ifndef WINCH_H_
#define WINCH_H_

#include <Arduino.h>

class Winch {
private:
    uint8_t _motorA;  // Pin for H-Bridge input A
    uint8_t _motorB;  // Pin for H-Bridge input B
    uint8_t _lock1;  // Pin for lock 1
    uint8_t _lock2;  // Pin for lock 2

public:
    /**
     * @brief Constructor for Winch motor control
     * @param motorA Pin controlling direction A
     * @param motorB Pin controlling direction B
     */
    Winch(uint8_t motorA, uint8_t motorB, u_int8_t lock1, u_int8_t lock2);

    /**
     * @brief Initializes the motor control pins
     */
    void init();

    /**
     * @brief Controls the winch motor speed and direction
     * @param percent Speed percentage (-100 to 100)
     */
    void motorControl(int percent);

    /**
     * @brief Stops the winch motor
     */
    void brake();

    /**
     * @brief Locks or unlocks the winch
     * @param lock True to lock, false to unlock
     */
    void setLock1(bool lock);

    /**
     * @brief Locks or unlocks the winch
     * @param lock True to lock, false to unlock
     */
    void setLock2(bool lock);
};

#endif /* WINCH_H_ */
