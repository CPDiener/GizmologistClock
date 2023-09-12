/*
 * Created by CPDiener on 9/11/2023
 * Allows for the creation of a plane for each number
 * */

#ifndef GIZMOCLOCK_PLANE_H
#define GIZMOCLOCK_PLANE_H

#include <Arduino.h>

class Plane
{
public:
    Plane(int xMin, int xMax, int yMin, int yMax);
    int getXMin();
    int getXMax();
    int getYMin();
    int getYMax();
    int getCenterX();
    int getCenterY();
    int getWidth();
    int getHeight();
private:
    int _xMin;
    int _xMax;
    int _yMin;
    int _yMax;
};

#endif //GIZMOCLOCK_PLANE_H
