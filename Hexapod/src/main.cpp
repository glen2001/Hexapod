#include <Arduino.h>
#include <Wire.h>
#include <LEG.h>
#include <HEXAPOD.h>
#include <ERROR_HANDLER.h>

enum HEXAPOD_STATUS {
    STARTUP,
    IDLE,
    RUNNING,
    ABORT
};

HEXAPOD_STATUS STATE = STARTUP;
HEXAPOD HEXAPOD_MAIN;

void setup() {
    delay(2000);
    Wire.begin(10, 3);
    Serial.begin(9600);
     
    HEXAPOD_MAIN.INITIALIZE();
    STATE = IDLE;
}

void loop() {
    switch(STATE) {
        case IDLE:
            // HEXAPOD_MAIN.IDLE();
            Serial.println("STATE: IDLE");
            delay(5000);
            break;
        case RUNNING:
            // HEXAPOD_MAIN.RUNNING();
            Serial.println("STATE: RUNNING");
            break;
        case ABORT:
            // HEXAPOD_MAIN.ABORT();
            Serial.println("STATE: ABORT");
            break;
    }
    
}
