/*
 * Created by CPDiener on 9/6/2023
 * Functions as the main file arduino file for the clock (replacing the typical .ino file)
 * */

#include <Arduino.h>
#include <Stepper.h>
#include <ClockFunction.h>

// Pins for the stepper motors
int dirPinLat = 2; // X direction pin
int stepPinLat = 3; // X step pin
int dirPinLong = 4; // Y direction pin
int stepPinLong = 5; // Y step pin

int latLowSwitch = 10; // X low limit switch
int latHighSwitch = 11; // X high limit switch
int longLowSwitch = 12; // Y low limit switch
int longHighSwitch = 13; // Y high limit switch

// Create the stepper motors
Stepper stepperLat = Stepper(stepPinLat, dirPinLat); // X stepper

void setup() {
  // Set the pin modes for the motors
  pinMode(stepPinLat, OUTPUT);
  pinMode(stepPinLong, OUTPUT);
  pinMode(dirPinLat, OUTPUT);
  pinMode(dirPinLong, OUTPUT);

  // Set the pin modes for the limit switches
  pinMode(latLowSwitch, INPUT);
  pinMode(latHighSwitch, INPUT);
  pinMode(longLowSwitch, INPUT);
  pinMode(longHighSwitch, INPUT);

  // Calibrate the stepper motors
  stepperLat.calibrate(latLowSwitch, latHighSwitch);
}

void loop() {

}
