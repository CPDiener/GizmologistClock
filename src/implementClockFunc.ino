#include <Arduino.h>
#include <ClockFunction.h>
#include <Stepper.h>

ClockFunction clockFunction(2, 3, 4, 5, 10, 11, 12, 13);

void setup() {
    clockFunction.begin();
}

void loop() {

}
