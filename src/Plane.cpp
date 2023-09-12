/*
 * Created by CPDiener on 9/11/2023
 * Allows for the creation of a plane for each number
 * */

#include <Arduino.h>
#include <Plane.h>

Plane::Plane(int xMin, int xMax, int yMin, int yMax)
        :
        _xMin(xMin),
        _xMax(xMax),
        _yMin(yMin),
        _yMax(yMax){
}

int Plane::getXMin() {
    return _xMin;
}

int Plane::getXMax() {
    return _xMax;
}

int Plane::getYMin() {
    return _yMin;
}

int Plane::getYMax() {
    return _yMax;
}

int Plane::getCenterX() {
    return (_xMax - _xMin) / 2;
}

int Plane::getCenterY() {
    return (_yMax - _yMin) / 2;
}

int Plane::getWidth() {
  return _xMax - _xMin;
}

int Plane::getHeight() {
    return _yMax - _yMin;
}


