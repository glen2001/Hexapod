#include <HEXAPOD.h>
#include <LEG.h>

HEXAPOD::HEXAPOD() 
    : DRIVER_1(0x40), 
    DRIVER_2(0x41), 
    LEGS {
        LEG(0, 1, 2, DRIVER_1),
        LEG(3, 4, 5, DRIVER_1),
        LEG(6, 7, 8, DRIVER_1),

        LEG(0, 1, 2, DRIVER_2),
        LEG(3, 4, 5, DRIVER_2),
        LEG(6, 7, 8, DRIVER_2)
    } {}

HEXAPOD::~HEXAPOD() {}

void HEXAPOD::INITIALIZE() {
    DRIVER_1.begin();
    DRIVER_2.begin();

    DRIVER_1.setPWMFreq(50);
    DRIVER_2.setPWMFreq(50);

    // Loop through legs and initialize

    for (auto& LEG_ : LEGS) {
        LEG_.INITIALIZE();
    }
}