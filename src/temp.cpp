///*
// * Created by CPDiener on 9/6/2023
// * Functions as the main file arduino file for the clock (replacing the typical .ino file)
// * */
//
//#include <Arduino.h>
//#include <Stepper.h>
//#include <Numbers.h>
//#include <ClockFunction.h>
//#include <Servo.h>
//
//Servo pen;
//
//int penPos = 20;
//
//// Pins for the stepper motors
//int dirPinLat = 2; // X direction pin
//int stepPinLat = 3; // X step pin
//int dirPinLong = 4; // Y direction pin
//int stepPinLong = 5; // Y step pin
//
//int penServoPin = 9; // Pen servo pin
//
//int blueLED = 7; // Blue LED pin
//
//int latLowSwitch = 10; // X low limit switch
//int latHighSwitch = 11; // X high limit switch
//
//int longLowSwitch = 13; // Y low limit switch
//
//int startButton = 12; // Start button
//
//
//// Create the stepper motors
//Stepper stepperLat = Stepper(stepPinLat, dirPinLat); // X stepper
//Stepper stepperLong = Stepper(stepPinLong, dirPinLong); // Y stepper
//
////Plane hourHighPlace = Plane(0,, 100, 600); // Plane for the hour high digit
//
//
//void setup() {
//  Serial.begin(9600);
//  // Set the pin modes for the motors
//  pinMode(stepPinLat, OUTPUT);
//  pinMode(stepPinLong, OUTPUT);
//  pinMode(dirPinLat, OUTPUT);
//  pinMode(dirPinLong, OUTPUT);
//
////  pen.attach(penServoPin);
//
//  pinMode(startButton, INPUT);
//
//  // Set the pin modes for the limit switches
//  pinMode(latLowSwitch, INPUT);
//  pinMode(latHighSwitch, INPUT);
//  pinMode(longLowSwitch, INPUT);
//
//
////  while(!digitalRead(startButton)) {
////    digitalWrite(blueLED, HIGH);
////    delay(100);
////    digitalWrite(blueLED, LOW);
////    delay(100);
////  }
////
////  delay(20);
//
//  // Calibrate the stepper motors
//
//
//  stepperLat.calibrate(latLowSwitch, latHighSwitch);
//  Serial.print(stepperLat._maxPosition);
//
//
////  stepperLong.calibrateOne(longLowSwitch);
//
//
////
////  penPos = 85;
////  pen.write(penPos);
////
////  pen.write(150);
//
//
//}
//
//void loop() {
//}
