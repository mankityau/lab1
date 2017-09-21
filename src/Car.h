#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
#include "State.h"
#include "physics.h"

class Car {
 private:
    std::string model;
    double mass;
    double engineForce;
    double dragArea;
    bool engineOn;
    State state;

 public:
  // constructor
  Car(std::string model, double mass, double engine_force, double drag_area);
  
  std::string getModel();    // gets the model name
  double getMass();          // mass of the car
  void accelerate(bool on);  // turn the accelerator on/off
  void drive(double dt);     // drive the car for an amount of time dt
  State getState();          // returns the car's state
    friend std::ostream& operator<<(std::ostream& os, Car& car);
};
#endif