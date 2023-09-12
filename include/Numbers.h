/*
 * Created by CPDiener on 9/11/2023
 * Provides the motor movement for numbers
 * */

#ifndef GIZMOCLOCK_LETTERS_H
#define GIZMOCLOCK_LETTERS_H

#include <Arduino.h>
#include <Plane.h>
#include <Stepper.h>
//#include <Servo.h>

class Numbers
{
public:
    void static draw0(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY);
    void static relativeMoveX(Stepper motorX, Plane numPlace, int relX);
//    void draw1(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY);
//    void draw2(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY);
//    void draw3(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY);
//    void draw4(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY);
//    void draw5(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY);
//    void draw6(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY);
//    void draw7(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY);
//    void draw8(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY);
//    void draw9(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY);
private:
    void static relativeMove(Stepper motorX, Stepper motorY, Plane numPlace, int relX, int relY);
};

#endif //GIZMOCLOCK_LETTERS_H
