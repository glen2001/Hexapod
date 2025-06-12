#include <HEXAPOD.h>
#include <LEG.h>
#include <ERROR_HANDLER.h>
#include <SPI.h>


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
    Serial.println("Initializing PWM Drivers");

    if (!ERROR_HANDLER::CHECK_CONDITION(DRIVER_1.begin(), "Failed to initialize DRIVER_1", true)) {
        return false;
    }

    Serial.println("Leg Driver 1 Successfully Initialized");

    if (!ERROR_HANDLER::CHECK_CONDITION(DRIVER_2.begin(), "Failed to initialize DRIVER_2", true)) {
        return false;
    }

    Serial.println("Leg Driver 2 Successfully Initialized");

    
    Serial.println("Initialization Successful");
    Serial.println();

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

bool HEXAPOD::SET_LEG_ANGLES(uint8_t LEG_INDEX, uint8_t SHOULDER, uint8_t ELBOW, uint8_t WRIST) {
    if (LEG_INDEX >= 6) {
        Serial.println("Invalid leg index");
        return false;
    }
    
    return LEGS[LEG_INDEX].SET_ANGLES(SHOULDER, ELBOW, WRIST);
}

uint8_t HEXAPOD::GET_LEG_ANGLES(uint8_t LEG_INDEX) {
    return LEGS[LEG_INDEX].GET_ANGLES();
}