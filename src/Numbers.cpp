/*
 * Created by CPDiener on 9/11/2023
 * Provides the motor movement for numbers
 * */

// Height is around 1.44 x width

#include <Arduino.h>
#include <Numbers.h>
#include <Plane.h>
#include <Stepper.h>

void Numbers::draw0(Stepper motorX, Stepper motorY, Plane numPlace, int currentX, int currentY) {
//  int width = numPlace.getWidth();
//  int height = numPlace.getHeight();

//  int relWidth = 100 * (width / height);
//  int relHeight = 100;

  relativeMove(motorX, motorY, numPlace, 15, 15);
}

void Numbers::relativeMoveX(Stepper motorX, Plane numPlace, int relX) {
  int width = numPlace.getWidth();
  int height = numPlace.getHeight();
  int relWidth = 100 * (width / height);
  int absX = ((relX / relWidth) * width) + numPlace.getXMin();
  motorX.moveTo(absX);

}

void Numbers::relativeMove(Stepper motorX, Stepper motorY, Plane numPlace, int relX, int relY) {
  int width = numPlace.getWidth();
  int height = numPlace.getHeight();

  int relWidth = 100 * (width / height);
  int relHeight = 100;

  int absX = ((relX / relWidth) * width) + numPlace.getXMin();
  int absY = ((relY / relHeight) * height) + numPlace.getYMin();

  motorX.moveTo(absX);
  motorY.moveTo(absY);
}