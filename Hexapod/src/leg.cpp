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

    DRIVER.writeMicroseconds(SHOULDER_CHANNEL, map(SHOULDER_ANGLE, 0, 180, PULSE_MIN, PULSE_MAX));
    DRIVER.writeMicroseconds(ELBOW_CHANNEL, map(ELBOW_ANGLE, 0, 180, PULSE_MIN, PULSE_MAX));
    DRIVER.writeMicroseconds(WRIST_CHANNEL, map(WRIST_ANGLE, 0, 180, PULSE_MIN, PULSE_MAX));

    return true;
}

bool LEG::MOVE_IK(float x, float y, float z) {
    // Calculate the azimuthal angle

    uint8_t shoulder_angle = atan2(y, x) * 180.0 / M_PI;

    // Effective reach and total length

    float r = sqrt(x * x + y * y);
    float L = sqrt(r * r + z * z);

    // Check if coordinate is out of reach

    if (L > (SHOULDER_LENGTH + ELBOW_LENGTH + WRIST_LENGTH)) {
        return false;
    }

    // Elbow angle calculation

    float cos_elbow = (ELBOW_LENGTH * ELBOW_LENGTH + WRIST_LENGTH * WRIST_LENGTH - L * L) / (2 * ELBOW_LENGTH * WRIST_LENGTH);
    uint8_t elbow_angle = 180 - acos(cos_elbow) * 180.0 / M_PI;

    // Shoulder angle calculation

    float shoulder_pitch = atan2(z, r) - asin((WRIST_LENGTH * sin(elbow_angle * M_PI / 180.0)) / L);
    uint8_t shoulder_pitch_angle = shoulder_pitch * 180.0 / M_PI;

    // Wrist angle calculation

    uint8_t wrist_angle = 180 - (shoulder_pitch_angle + elbow_angle);

    return SET_ANGLES(shoulder_pitch_angle, elbow_angle, wrist_angle);
}