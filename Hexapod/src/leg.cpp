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

    return (SHOULDER_ANGLE << 16) | (ELBOW_ANGLE << 8) | (WRIST_ANGLE);
}

bool LEG::SET_ANGLES(uint8_t SHOULDER_ANGLE, uint8_t ELBOW_ANGLE, uint8_t WRIST_ANGLE) {
    // Checks if input angle is in acceptable range

    if (SHOULDER_ANGLE > 180 || ELBOW_ANGLE > 180 || WRIST_ANGLE > 180) {
        return false;
    }

    this->SHOULDER_ANGLE = SHOULDER_ANGLE;
    this->ELBOW_ANGLE = ELBOW_ANGLE;
    this->WRIST_ANGLE = WRIST_ANGLE;

    const int PULSE_MIN = 500;
    const int PULSE_MAX = 2500;

    DRIVER.writeMicroseconds(SHOULDER_CHANNEL, map(SHOULDER_ANGLE, 0, 180, PULSE_MIN, PULSE_MAX));
    DRIVER.writeMicroseconds(ELBOW_CHANNEL, map(ELBOW_ANGLE, 0, 180, PULSE_MIN, PULSE_MAX));
    DRIVER.writeMicroseconds(WRIST_CHANNEL, map(WRIST_ANGLE, 0, 180, PULSE_MIN, PULSE_MAX));

    return true;
}

bool LEG::MOVE_IK(float x, float y, float z) {
    // Placeholder for IK calculations

    uint8_t calculated_shoulder_angle = /* IK calculation */;
    uint8_t calculated_elbow_angle = /* IK calculation */;
    uint8_t calculated_wrist_angle = /* IK calculation */;

    SET_ANGLES(calculated_shoulder_angle, calculated_elbow_angle, calculated_wrist_angle);
}