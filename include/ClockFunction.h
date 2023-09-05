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
    static void calibrate(Stepper &motor, int minSwitchPin, int maxSwitchPin, bool &isCalibrated);
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