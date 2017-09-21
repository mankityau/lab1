#include <vector>
#include <iostream>
#include "Car.h"
#include "Herbie.h"
#include "Mazda3.h"
#include "Prius.h"
#include "Tesla3.h"

static int TYPES_OF_CARS = 4;
static double TARGET_SPEED = 23.8;
static double TARGET_DURATION = 180; //3 minutes
static double DT = 0.1;

Car* createRandomCar();

int main() {
  std::vector<Car*> cars;
  for(int i = 0; i < 100; i ++){
    cars.push_back(createRandomCar());
  }

  for (double timePassed = 0; timePassed < TARGET_DURATION; timePassed += DT){
    for (Car* car: cars){
      car->accelerate(car->getState()->velocity < TARGET_SPEED);
      car->drive(DT);
      std::cout << *car << std::endl;
    }
  }
  return 0;
}

Car* createRandomCar(){
  switch (rand() % TYPES_OF_CARS) {
    case 0:
      return new Herbie();
    case 1:
      return new Mazda3();
    case 2:
      return new Prius();
    case 3:
      return new Tesla3();
    default:
      throw "Failed to generate cars";
  }
}