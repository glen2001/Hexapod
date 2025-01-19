#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN_1 9
#define SERVO_PIN_2 10
#define SERVO_PIN_3 11

Servo SERVO_1;
Servo SERVO_2;
Servo SERVO_3;

int SERVO_1_ANGLE = 90;
int SERVO_2_ANGLE = 90;
int SERVO_3_ANGLE = 90;

void setup() {
    SERVO_1.attach(SERVO_PIN_1);
    SERVO_2.attach(SERVO_PIN_2);
    SERVO_3.attach(SERVO_PIN_3);

    SERVO_1.write(90);
    SERVO_2.write(90);
    SERVO_3.write(90);
}

void loop() {
    SERVO_1.write(SERVO_1_ANGLE);
    delay(50);
    SERVO_1_ANGLE++;


    if(SERVO_1_ANGLE >= 120) {
        SERVO_1_ANGLE = 60;
    }
    
}
