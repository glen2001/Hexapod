#include <Arduino.h>
#include <Servo.h>
#include <LEG.h>
#include <HEXAPOD.h>
#include <ERROR_HANDLER.h>

void setup() {
    Serial.begin(9600);

    HEXAPOD HEXAPOD; 
    HEXAPOD.INITIALIZE();
}

void loop() {

}
