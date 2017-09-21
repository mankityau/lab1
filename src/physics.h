#ifndef PHYSICS_H
#define PHYSICS_H

// 1D physics library
namespace physics {

double compute_position(double x0, double v, double dt);
double compute_velocity(double v0, double a, double dt);
double compute_velocity(double x0, double t0, double x1, double t1);
double compute_acceleration(double v0, double t0, double v1, double t1);
double compute_acceleration(double f, double m);
    double computeDragForce(double velocity, double dragArea);

}

#endif // PHYSICS_H