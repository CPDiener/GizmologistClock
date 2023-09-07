// What we worked on during our meeting on 9/6/2023
// Needs to be uploaded from Arduino.ide
// Will not be used in the future, just for reference

#include <Arduino.h>
#include <Stepper.h>

// Define the pin connections to the motors
int dirPinLat = 2;
int stepPinLat = 3;
int dirPinLong = 4;
int stepPinLong = 5;

// Define the pin connections to the limit switches
int latLowSwitch = 10;
int latHighSwitch = 11;
int longLowSwitch = 12;
int longHighSwitch = 13;

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

}

// With current code commented out, this will move the x motor up the board
void loop() {
  digitalWrite(dirPinLat, HIGH);
//  digitalWrite(dirPinLong, HIGH);
  digitalWrite(stepPinLat, HIGH);
//  digitalWrite(stepPinLong, HIGH);
  delayMicroseconds(700);
  digitalWrite(stepPinLat, LOW);
//  digitalWrite(stepPinLong, LOW);
  delayMicroseconds(700);
}
