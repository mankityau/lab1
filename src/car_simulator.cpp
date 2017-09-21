// CAR_SIMULATOR
#include <iostream>
#include "physics.h"

// air density
const double air_density = 1.225;

int main() {

    // read in car mass
    std::cout << "Enter the mass of the car (kg): ";
    double mass;
    std::cin >> mass;

    // read in engine force
    std::cout << "Enter the net force of the engine (N): ";
    double engine_force;
    std::cin >> engine_force;

    // read in drag coefficient
    std::cout << "Enter the car's drag area (m^2): ";
    double drag_area;
    std::cin >> drag_area;

    // read in time step
    std::cout << "Enter the simulation time step (s): ";
    double dt;
    std::cin >> dt;

    // read in total simulation time
    std::cout << "Enter the number of time steps (int): ";
    int N;
    std::cin >> N;

    // initialize the car's state
    double totalForce = 0;
    double x = 0;  // initial position
    double v = 0;  // initial velocity
    double a = 0;  // computed acceleration
    double t = 0;  // initial time

    // run the simulation
    for (int i = 0; i < N; ++i) {

        // COMPUTE UPDATED STATE HERE
        totalForce = engine_force + physics::computeDragForce(v, drag_area);
        a = physics::compute_acceleration(totalForce, mass);
        v = physics::compute_velocity(v, a, dt);
        x = physics::compute_position(x, v, dt);

        t += dt;  // increment time

        // print the time and current state
        std::cout << "t: " << t << ", a: " << a
                  << ", v: " << v << ", x: " << x << std::endl;
    }

    return 0;
}