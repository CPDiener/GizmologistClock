//
// Created by phild on 9/18/2023.
//

/*
 * Created by CPDiener on 9/6/2023
 * Functions as the main file arduino file for the clock (replacing the typical .ino file)
 * */

#include <Arduino.h>
#include <Stepper.h>
#include <ClockFunction.h>
#include <Servo.h>
#include "Plane.h"

Servo pen;

int penPos = 20;

// Pins for the stepper motors
int dirPinLat = 2; // X direction pin
int stepPinLat = 3; // X step pin
int dirPinLong = 4; // Y direction pin
int stepPinLong = 5; // Y step pin

int penServoPin = 9; // Pen servo pin

int blueLED = 7; // Blue LED pin

int latLowSwitch = 10; // X low limit switch
int latHighSwitch = 11; // X high limit switch

int longLowSwitch = 13; // Y low limit switch

int startButton = 12; // Start button
int downButton = 6;


// Create the stepper motors
Stepper stepperLat = Stepper(stepPinLat, dirPinLat); // X stepper
Stepper stepperLong = Stepper(stepPinLong, dirPinLong); // Y stepper

Plane hourLowPlace = Plane(56, 377, 0, 686); // Plane for the hour low digit
Plane hourHighPlace = Plane(526, 851, 0, 686); // Plane for the hour high digit

Plane minuteLowPlace = Plane(1014, 1331, 0, 686); // Plane for the minute low digit
Plane minuteHighPlace = Plane(1495, 1762, 0, 686); // Plane for the minute-high digit

void relativeMove(Stepper motorX, Stepper motorY, Plane numPlace, int relX, int relY) {
  int width = numPlace.getWidth();
  int height = numPlace.getHeight();

  int relWidth = 100 * (width / height);
  int relHeight = 100;

  int absX = ((relX / relWidth) * width) + numPlace.getXMin();
  int absY = ((relY / relHeight) * height) + numPlace.getYMin();

  motorX.moveTo(absX);
  motorY.moveTo(absY);
}

void draw0(Stepper motorX, Stepper motorY, Plane numPlace) {
  relativeMove(motorX, motorY, numPlace, 10, 10);
  // servo down
  relativeMove(motorX, motorY, numPlace, 10, 90);
  relativeMove(motorX, motorY, numPlace, 90, 90);
  relativeMove(motorX, motorY, numPlace, 90, 10);
  relativeMove(motorX, motorY, numPlace, 10, 10);
}

void setup() {
  Serial.begin(9600);
  // Set the pin modes for the motors
  pinMode(stepPinLat, OUTPUT);
  pinMode(stepPinLong, OUTPUT);
  pinMode(dirPinLat, OUTPUT);
  pinMode(dirPinLong, OUTPUT);


  pinMode(startButton, INPUT);
  pinMode(downButton, INPUT);

  // Set the pin modes for the limit switches
  pinMode(latLowSwitch, INPUT);
  pinMode(latHighSwitch, INPUT);
  pinMode(longLowSwitch, INPUT);


  // Calibrate the stepper motors
  stepperLat.calibrate(latLowSwitch, latHighSwitch);
  stepperLong.calibrateOne(longLowSwitch);
  stepperLong.moveTo(0);

  draw0(stepperLat, stepperLong, hourLowPlace);
}

void loop() {
}

