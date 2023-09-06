#include <Arduino.h>
#include <Stepper.h>

Stepper::Stepper(int stepPin, int dirPin)
        :
        _stepPin(stepPin),
        _dirPin(dirPin),
        _currentPosition(0),
        _maxPosition(0){
}

void Stepper::setPos(int pos) {
    _currentPosition = pos;
}

int Stepper::getPos() {
    return _currentPosition;
}

void Stepper::moveTo(long absolute) {
    if (absolute > _maxPosition) {
        absolute = _maxPosition;
    } else if (absolute < 0) {
        absolute = 0;
    }
    while (_currentPosition != absolute) {
        if (absolute > _currentPosition) {
            digitalWrite(_dirPin, HIGH);
            digitalWrite(_stepPin, HIGH);
            delay(1);
            digitalWrite(_stepPin, LOW);
            delay(1);
            _currentPosition++;
        } else if (absolute < _currentPosition) {
            digitalWrite(_dirPin, LOW);
            digitalWrite(_stepPin, HIGH);
            delayMicroseconds(700);
            digitalWrite(_stepPin, LOW);
            delayMicroseconds(700);
            _currentPosition--;
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