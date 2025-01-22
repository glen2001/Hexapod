#ifndef HEXAPOD_H
#define HEXAPOD_H

#include <LEG.h>


class HEXAPOD {
    private:
        Adafruit_PWMServoDriver DRIVER_1;
        Adafruit_PWMServoDriver DRIVER_2;
        LEG LEGS[6];

    public:
        HEXAPOD();
        ~HEXAPOD();

        bool INITIALIZE();
        bool MOVE_LEG(uint8_t leg_index, float x, float y, float z);
};

#endif