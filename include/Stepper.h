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
    int getPos();
    void moveUp();
    void moveDown();
    void moveTo(long absolute);
    void setLimit(int max);
    void calibrate(int minSwitchPin, int maxSwitchPin);
private:
    int _stepPin;
    int _dirPin;
    int _currentPosition;
    int _maxPosition;
    bool _isCalibrated = false;
};

#endif //GIZMOCLOCK_STEPPER_H
