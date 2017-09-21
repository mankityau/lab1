#include "Car.h"

// implementation details...
Car::Car(std::string model, double mass, double engine_force, double drag_area) {
    this->model = model;
    this->mass = mass;
    this->engineForce = engine_force;
    this->dragArea = drag_area;
    this->engineOn = false;
    this->state = State();
}

std::string Car::getModel() {
    return model;
}

double Car::getMass() {
    return mass;
}

void Car::accelerate(bool on) {
    engineOn = on;
}

void Car::drive(double dt) {
    double currentVelocity = state.velocity;
    double currentPosition = state.position;
    double currentTime = state.time;

    double totalForce = (engineOn ? engineForce : 0) - physics::computeDragForce(currentVelocity, dragArea);
    double updatedAcceleration = physics::compute_acceleration(totalForce, mass);
    double updatedVelocity = physics::compute_velocity(currentVelocity, updatedAcceleration, dt);
    double updatedPosition = physics::compute_position(currentPosition, updatedVelocity, dt);
    double updateTime = currentTime + dt;
    state.set(updatedPosition, updatedVelocity, updatedAcceleration, updateTime);
}

State *Car::getState() {
    return &state;
}

std::ostream &operator<<(std::ostream &os, Car &car) {
    os << "model: " << car.model
       << ", state: " << car.state;
    return os;
}

bool Car::isEngineOn() {
    return engineOn;
}
