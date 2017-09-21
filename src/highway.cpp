#include <vector>
#include <iostream>
#include "Car.h"
#include "Mazda3.h"
#include "Prius.h"
#include "Tesla3.h"

static double TARGET_SPEED = 23.8;
static double TARGET_DURATION = 180; //3 minutes
static double DT = 0.1;

int main() {
    Car *carTesla[100];
    Car **carMazda = new Car *[100];
    std::vector<Car *> carPrius(100);

    for (int i = 0; i < 100; ++i) {
        carTesla[i] = new Prius();   // fixed-size array
        carMazda[i] = new Mazda3();  // dynamic array
        carPrius[i] = new Tesla3();  // vector
    }
    for (double timePassed = 0; timePassed < TARGET_DURATION; timePassed += DT) {
        for (Car *car: carTesla) {
            car->accelerate(car->getState()->velocity < TARGET_SPEED);
            car->drive(DT);
            std::cout << *car << std::endl;
        }

        for (int i = 0; i < 100; ++i) {
            carMazda[i]->accelerate(carMazda[i]->getState()->velocity < TARGET_SPEED);
            carMazda[i]->drive(DT);
            std::cout << *carMazda[i] << std::endl;
        }

        for (Car *car: carPrius) {
            car->accelerate(car->getState()->velocity < TARGET_SPEED);
            car->drive(DT);
            std::cout << *car << std::endl;
        }
    }

    for (int i = 0; i < 100; ++i) {
        delete carTesla[i];  // fixed-size array
        delete carMazda[i];  // dynamic array
        delete carPrius[i];  // vector
    }

    delete[] carMazda;
    return 0;
}