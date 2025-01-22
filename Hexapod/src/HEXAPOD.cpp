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

bool HEXAPOD::INITIALIZE() {
    if (!DRIVER_1.begin()) {
        Serial.println("Error initializing DRIVER_1");
        return false;
    }
    if (!DRIVER_2.begin()) {
        Serial.println("Error initializing DRIVER_2");
        return false;
    }

    DRIVER_1.setPWMFreq(50);
    DRIVER_2.setPWMFreq(50);

    // Loop through legs and initialize

    for (auto& LEG_ : LEGS) {
        LEG_.INITIALIZE();
    }

    return true;
}

bool HEXAPOD::MOVE_LEG(uint8_t LEG_INDEX, float x, float y, float z) {
    if (LEG_INDEX >= 6) {
        Serial.println("Invalid leg index");
        return false;
    }
    
    return LEGS[LEG_INDEX].MOVE_IK(x, y, z);
}