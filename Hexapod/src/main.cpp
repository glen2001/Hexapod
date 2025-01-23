#include <Arduino.h>
#include <Servo.h>
#include <LEG.h>
#include <SPI.h>

Servo servo;

void setup() {
    servo.attach(9);
    servo.write(90);
}

void loop() {

    
}
