/*
 * Created by CPDiener on 9/6/2023
 * Provides the framework for the clock functionality
 * */

#include <Arduino.h>
#include <ClockFunction.h>
#include <Stepper.h>

ClockFunction::ClockFunction(int stepPinLat, int dirPinLat, int stepPinLong, int dirPinLong, int latLowSwitch,
                             int latHighSwitch, int longLowSwitch, int longHighSwitch)
        :
        _stepPinLat(stepPinLat),
        _dirPinLat(dirPinLat),
        _stepPinLong(stepPinLong),
        _dirPinLong(dirPinLong),
        _latLowSwitch(latLowSwitch),
        _latHighSwitch(latHighSwitch),
        _longLowSwitch(longLowSwitch),
        _longHighSwitch(longHighSwitch),
        _stepperLat(Stepper(stepPinLat, dirPinLat)),
        _stepperLong(Stepper(stepPinLong, dirPinLong)) {
}

void ClockFunction::begin() {
    pinMode(_stepPinLat, OUTPUT);
    pinMode(_stepPinLong, OUTPUT);
    pinMode(_dirPinLat, OUTPUT);
    pinMode(_dirPinLong, OUTPUT);

    pinMode(_latLowSwitch, INPUT);
    pinMode(_latHighSwitch, INPUT);
    pinMode(_longLowSwitch, INPUT);
    pinMode(_longHighSwitch, INPUT);
}
