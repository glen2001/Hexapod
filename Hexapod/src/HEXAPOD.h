#ifndef HEXAPOD_H
#define HEXAPOD_H

#include <LEG.h>


class HEXAPOD {
    private:
        LEG LEGS[6];
        Adafruit_PWMServoDriver DRIVER_1;
        Adafruit_PWMServoDriver DRIVER_2;

    public:
        HEXAPOD();
        ~HEXAPOD();

        void INITIALIZE();
};

#endif