#ifndef LEG_H
#define LEG_H

#include <stdint.h>
#include <Adafruit_PWMServoDriver.h>


class LEG {
    private:
        uint8_t SHOULDER_CHANNEL, ELBOW_CHANNEL, WRIST_CHANNEL;
        uint8_t SHOULDER_ANGLE, ELBOW_ANGLE, WRIST_ANGLE;
        Adafruit_PWMServoDriver& DRIVER;

    public:
        LEG(uint8_t SHOULDER_CHANNEL, uint8_t ELBOW_CHANNEL, uint8_t WRIST_CHANNEL, Adafruit_PWMServoDriver& DRIVER);
        ~LEG();

        void INITIALIZE();
        uint32_t GET_ANGLES();
        bool SET_ANGLES(uint8_t SHOULDER_ANGLE, uint8_t ELBOW_ANGLE, uint8_t WRIST_ANGLE);
        bool MOVE_IK(float x, float y, float z);
};

#endif