/*
 * Created by CPDiener on 9/6/2023
 * Provides basic stepper motor functionality
 * */

#ifndef GIZMOCLOCK_STEPPER_H
#define GIZMOCLOCK_STEPPER_H

#include <Arduino.h>

class Stepper
{
public:
    Stepper(int stepPin, int dirPin);
    void setPos(int pos);
    int getPos() const;
    void moveUp();
    void moveDown();
    void moveTo(int absolute);
    void setLimit(int max);
    void calibrate(int minSwitchPin, int maxSwitchPin);
    void calibrateOne(int switchPin);
    int _maxPosition;
private:
    int _stepPin;
    int _dirPin;
    int _currentPosition;
    bool _isCalibrated = false;
};

#endif //GIZMOCLOCK_STEPPER_H
