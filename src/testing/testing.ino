#include <Arduino.h>
#include <Stepper.h>


int dirPinLat = 2;
int stepPinLat = 3;
int dirPinLong = 4;
int stepPinLong = 5;

int latLowSwitch = 10;
int latHighSwitch = 11;
int longLowSwitch = 12;
int longHighSwitch = 13;

Stepper* stepperLat = new Stepper(stepPinLat, dirPinLat);


void setup() {
  pinMode(stepPinLat, OUTPUT);
  pinMode(stepPinLong, OUTPUT);
  pinMode(dirPinLat, OUTPUT);
  pinMode(dirPinLong, OUTPUT);

  pinMode(latLowSwitch, INPUT);
  pinMode(latHighSwitch, INPUT);
  pinMode(longLowSwitch, INPUT);
  pinMode(longHighSwitch, INPUT);

}

void loop() {
//  digitalWrite(dirPinLat, HIGH);
//  digitalWrite(dirPinLong, HIGH);
//  digitalWrite(stepPinLat, HIGH);
//  digitalWrite(stepPinLong, HIGH);
//  delayMicroseconds(700);
//  digitalWrite(stepPinLat, LOW);
//  digitalWrite(stepPinLong, LOW);
//  delayMicroseconds(700);

  stepperLat->moveUp();
}
