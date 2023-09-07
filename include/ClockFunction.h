/*
 * Created by CPDiener on 9/6/2023
 * Provides the framework for the clock functionality
 * */

#ifndef GIZMOCLOCK_CLOCKFUNCTION_H
#define GIZMOCLOCK_CLOCKFUNCTION_H

#include <Arduino.h>
#include "Stepper.h"

class ClockFunction
{
public:
    ClockFunction(int stepPinLat, int dirPinLat, int stepPinLong, int dirPinLong, int latLowSwitch, int latHighSwitch,
                  int longLowSwitch, int longHighSwitch);
    void begin();
private:
    int _stepPinLat;
    int _dirPinLat;
    int _stepPinLong;
    int _dirPinLong;
    int _latLowSwitch;
    int _latHighSwitch;
    int _longLowSwitch;
    int _longHighSwitch;
    Stepper _stepperLat;
    Stepper _stepperLong;
};

#endif //GIZMOCLOCK_CLOCKFUNCTION_H