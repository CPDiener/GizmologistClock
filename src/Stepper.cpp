/*
 * Created by CPDiener on 9/6/2023
 * Provides basic stepper motor functionality
 * */

#include <Arduino.h>
#include <Stepper.h>

Stepper::Stepper(int stepPin, int dirPin)
        :
        _maxPosition(0),
        _stepPin(stepPin),
        _dirPin(dirPin),
        _currentPosition(0){
}

void Stepper::setPos(int pos) {
    _currentPosition = pos;
}

int Stepper::getPos() const {
    return _currentPosition;
}

void Stepper::moveTo(int absolute) {
  if (absolute < 0) {
    absolute = 0;
  }
  while (_currentPosition != absolute) {
      if (absolute > _currentPosition) {
        this->moveUp();
      } else if (absolute < _currentPosition) {
        this->moveDown();
      }
  }
}

void Stepper::moveUp() {
    digitalWrite(_dirPin, HIGH);
    digitalWrite(_stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(_stepPin, LOW);
    delayMicroseconds(700);
    _currentPosition++;
}

void Stepper::moveDown() {
    digitalWrite(_dirPin, LOW);
    digitalWrite(_stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(_stepPin, LOW);
    delayMicroseconds(700);
    _currentPosition--;
}

void Stepper::setLimit(int max) {
    _maxPosition = max;
}

void Stepper::calibrate(int minSwitchPin, int maxSwitchPin) {
  while (!digitalRead(minSwitchPin)) {
    this->moveDown();
  }

  for (int i = 0; i < 100; i++) {
    moveUp();
  }

  while(!digitalRead(minSwitchPin)) {
    digitalWrite(_dirPin, LOW);
    digitalWrite(_stepPin, HIGH);
    delay(5);
    digitalWrite(_stepPin, LOW);
    delay(5);
    _currentPosition--;
  }

  this->setPos(0);

  while (!digitalRead(maxSwitchPin)) {
    this->moveUp();
  }

  for (int i = 0; i < 100; i++) {
    moveDown();
  }

  while(!digitalRead(maxSwitchPin)) {
    digitalWrite(_dirPin, HIGH);
    digitalWrite(_stepPin, HIGH);
    delay(5);
    digitalWrite(_stepPin, LOW);
    delay(5);
    _currentPosition++;
  }

  int maxPos = this->getPos();
  this->setLimit(maxPos);

  this->moveTo(maxPos / 2);

  _isCalibrated = true;

}

void Stepper::calibrateOne(int switchPin) {
  while (!digitalRead(switchPin)) {
    this->moveDown();
  }

  for (int i = 0; i < 100; i++) {
    moveUp();
  }

  while(!digitalRead(switchPin)) {
    digitalWrite(_dirPin, LOW);
    digitalWrite(_stepPin, HIGH);
    delay(5);
    digitalWrite(_stepPin, LOW);
    delay(5);
    _currentPosition--;
  }

  this->setPos(0);

  this->moveTo(800);

  _isCalibrated = true;
}