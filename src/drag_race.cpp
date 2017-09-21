#include "Car.h"

#include <iostream>
#include <string>
#include "State.h"
#include "Car.h"

static const double QUARTER_MILE = 402.3;

int main() {

  Car car1("Mazda 3", 1600, 790, 0.61);
  Car car2("Toyota Prius", 1450, 740, 0.58);

  // drive for 60 seconds
  double dt = 0.01;

  // GO!!!!
  car1.accelerate(true);
  car2.accelerate(true);
  for (double t = 0; t <= 60; t += dt) {
    car1.drive(dt);
    car2.drive(dt);
    // XXX print out who's in the lead
      std::cout << "The car in the lead right now is...";
      if (car1.getState()->position > car2.getState()->position) {
          std::cout << car1 << std::endl;
      } else if (car1.getState()->position < car2.getState()->position) {
          std::cout << car2 << std::endl;
      } else {
          std::cout << "looks like they are at the same position" << std::endl;
      }
  }

  return 0;
}