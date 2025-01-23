#include <LEG.h>
#include <stdint.h>
#include <Adafruit_PWMServoDriver.h>


LEG::LEG(uint8_t SHOULDER_CHANNEL, uint8_t ELBOW_CHANNEL, uint8_t WRIST_CHANNEL, Adafruit_PWMServoDriver& DRIVER)
        : SHOULDER_CHANNEL(SHOULDER_CHANNEL), 
        ELBOW_CHANNEL(ELBOW_CHANNEL), 
        WRIST_CHANNEL(WRIST_CHANNEL), 
        DRIVER(DRIVER) {}

LEG::~LEG() {}

void LEG::INITIALIZE() {
    // Sets joint angles to default positions

    uint8_t SHOULDER_ANGLE = 90;
    uint8_t ELBOW_ANGLE = 45;
    uint8_t WRIST_ANGLE = 135;

    SET_ANGLES(SHOULDER_ANGLE, ELBOW_ANGLE, WRIST_ANGLE);
}

uint32_t LEG::GET_ANGLES() {
    // Packs angle values into one uint32_t

    return (static_cast<uint32_t>(SHOULDER_ANGLE) << 16) | (static_cast<uint32_t>(ELBOW_ANGLE) << 8) | static_cast<uint32_t>(WRIST_ANGLE);
}

bool LEG::SET_ANGLES(uint8_t SHOULDER_ANGLE, uint8_t ELBOW_ANGLE, uint8_t WRIST_ANGLE) {
    // Checks if input angle is in acceptable range

    if (SHOULDER_ANGLE > 180 || ELBOW_ANGLE > 180 || WRIST_ANGLE > 180) {
        return false;
    }

    this->SHOULDER_ANGLE = SHOULDER_ANGLE;
    this->ELBOW_ANGLE = ELBOW_ANGLE;
    this->WRIST_ANGLE = WRIST_ANGLE;

    DRIVER.writeMicroseconds(SHOULDER_CHANNEL, map(SHOULDER_ANGLE, 0, 180, PULSE_MIN, PULSE_MAX));
    DRIVER.writeMicroseconds(ELBOW_CHANNEL, map(ELBOW_ANGLE, 0, 180, PULSE_MIN, PULSE_MAX));
    DRIVER.writeMicroseconds(WRIST_CHANNEL, map(WRIST_ANGLE, 0, 180, PULSE_MIN, PULSE_MAX));

    return true;
}

bool LEG::MOVE_IK(float x, float y, float z) {
    //PLACEHOLDER FUCNTION -- IMPLIMENT LATER

    // Checks if coordinate is accessible

    float distance = sqrt(x * x + y * y + z * z); 
    if (distance > (SHOULDER_LENGTH + ELBOW_LENGTH + WRIST_LENGTH)) {
        return false;
    }

    uint8_t CALCULATED_SHOULDER_ANGLE; // CALCULATE LATER
    uint8_t CALCULATED_ELBOW_ANGLE;
    uint8_t CALCULATED_WRIST_ANGLE;

    return SET_ANGLES(CALCULATED_SHOULDER_ANGLE, CALCULATED_ELBOW_ANGLE, CALCULATED_WRIST_ANGLE);
}