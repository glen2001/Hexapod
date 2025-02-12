#include <Arduino.h>
#include <LEG.h>
#include <HEXAPOD.h>
#include <ERROR_HANDLER.h>
#include <Wire.h>

void setup() {
    Wire.begin(45, 48);
    Serial.begin(115200);

    HEXAPOD HEXAPOD; 
    HEXAPOD.INITIALIZE();
}

void loop() {
    Serial.println("Hello World!");
}
