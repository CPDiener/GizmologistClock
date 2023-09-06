#include <Arduino.h>
#include <ClockFunction.h>
#include <Stepper.h>

ClockFunction clockFunction(3, 2, 5, 4, 10, 11, 12, 13);

void setup() {
    clockFunction.begin();
}

void loop() {

}
