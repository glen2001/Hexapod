#ifndef LEG_H
#define LEG_H

#include <stdint.h>
#include <Adafruit_PWMServoDriver.h>


class LEG {
    private:
        uint8_t SHOULDER_CHANNEL, ELBOW_CHANNEL, WRIST_CHANNEL;
        uint8_t SHOULDER_ANGLE, ELBOW_ANGLE, WRIST_ANGLE;
        uint8_t DRIVER_ADDRESS;
        Adafruit_PWMServoDriver DRIVER;

    public:
        LEG(uint8_t SHOULDER_CHANNEL, uint8_t ELBOW_CHANNEL, uint8_t WRIST_CHANNEL, uint8_t DRIVER_ADDRESS);
        ~LEG();

        uint32_t GET_ANGLES();
        bool SET_ANGLES(uint8_t SHOULDER_ANGLE, uint8_t ELBOW_ANGLE, uint8_t WRIST_ANGLE);
        void MOVE_IK(float x, float y, float z);
};

#endif