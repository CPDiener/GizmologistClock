#include <Arduino.h>
#include <AccelStepper.h>


const int stepPinLat = 2;
const int dirPinLat = 3;

const int stepPinLong = 4;
const int dirPinLong = 5;

const int latLowSwitch = 10;
const int latHighSwitch = 11;

const int longLowSwitch = 12;
const int longHighSwitch = 13;

AccelStepper stepLat(AccelStepper::DRIVER, stepPinLat, dirPinLat);
AccelStepper stepLong(AccelStepper::DRIVER, stepPinLong, dirPinLong);

const int gridWidth = 200;
const int gridHeight = 100;

bool isLatCalibrated = false;
bool isLongCalibrated = false;

void setup() {
    pinMode(latLowSwitch,INPUT_PULLUP);
    pinMode(latHighSwitch,INPUT_PULLUP);
    pinMode(longLowSwitch,INPUT_PULLUP);
    pinMode(longHighSwitch,INPUT_PULLUP);

    stepLat.setMaxSpeed(10);  // Set max speed (steps per second)
    stepLat.setAcceleration(5);  // Set acceleration (steps per second^2)

    stepLong.setMaxSpeed(10);
    stepLong.setAcceleration(5);

    while ( !isLatCalibrated ) {
        calibrate(stepLat, latLowSwitch, latHighSwitch, isLatCalibrated);
    }

    while ( !isLongCalibrated ) {
        calibrate(stepLong, longLowSwitch, longHighSwitch, isLongCalibrated);
    }
}

void loop() {

}

void calibrate(AccelStepper &motor, int minSwitchPin, int maxSwitchPin, bool &isCalibrated) {
    while(digitalRead(latLowSwitch)) {
        motor.setSpeed(-10);
        motor.runSpeed();
    }
    motor.setCurrentPosition(0);

    while(digitalRead(latHighSwitch)) {
        motor.setSpeed(10);
        motor.runSpeed();
    }
    motor.setCurrentPosition(gridWidth);
    isCalibrated = true;
}