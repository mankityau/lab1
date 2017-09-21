#include <vector>
#include "Car.h"
#include "Herbie.h"
#include "Mazda3.h"
#include "Prius.h"
#include "Tesla3.h"

static const double QUARTER_MILE = 402.3;

bool allCarFinished(std::vector<Car*> cars);
void announceLeader(std::vector<Car*> cars);

int main() {
    std::vector<Car*> cars;
    cars.push_back(new Mazda3());
    cars.push_back(new Prius());
    cars.push_back(new Tesla3());
    cars.push_back(new Herbie());

    double dt = 0.01;

    // GO!!!!
    for (Car* car: cars){
        car->accelerate(true);
    }

    while (!allCarFinished(cars)) {
        for (Car* car: cars){
            car->drive(dt);
            if ((car->isEngineOn()) && (car->getState()->position > QUARTER_MILE)) {
                car->accelerate(false);
                std::cout << car->getModel() << " finished with the Time: " << car->getState()->time << std::endl;
            }
        }

        announceLeader(cars);
    }
    return 0;
}

bool allCarFinished(std::vector<Car*> cars) {
    for (Car* car: cars){
        if (car->isEngineOn()) {
            return false;
        }
    }
    return true;
}

//This function is bias toward the "car at the top of the vector"
void announceLeader(std::vector<Car*> cars){
    Car* leadingCar = cars.front();
    for (Car* car : cars) {
        if (car->getState()->position > leadingCar ->getState()->position) {
            leadingCar = car;
        }
    }
    std::cout << "The leading car is " << *leadingCar << std::endl;
}