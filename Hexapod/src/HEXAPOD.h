#ifndef HEXAPOD_H
#define HEXAPOD_H

#include <LEG.h>
#include <SPI.h>


class HEXAPOD {
    private:
        Adafruit_PWMServoDriver DRIVER_1;
        Adafruit_PWMServoDriver DRIVER_2;
        LEG LEGS[6];

    public:
        HEXAPOD();
        ~HEXAPOD();

        bool INITIALIZE();
        bool MOVE_LEG(uint8_t LEG_INDEX, float x, float y, float z);
        bool SET_LEG_ANGLES(uint8_t LEG_INDEX, uint8_t SHOULDER, uint8_t ELBOW, uint8_t WRIST);
        uint8_t GET_LEG_ANGLES(uint8_t LEG_INDEX);
};

#endif