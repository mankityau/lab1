#include <cmath>
// 1D physics library
namespace physics {
// library implementation
    static double airDensity = 1.225;

    double compute_position(double x0, double v, double dt) {
        return x0 + v * dt;
    }
    double compute_velocity(double v0, double a, double dt) {
        return v0 + a * dt;
    }
    double compute_velocity(double x0, double t0, double x1, double t1) {
        return (x1 - x0) / (t1 - t0);
    }
    double compute_acceleration(double v0, double t0, double v1, double t1) {
        return (v1 - v0) / (t1 - t0);
    }
    double compute_acceleration(double f, double m) {
        return f / m;
    }

    double computeDragForce(double velocity, double dragArea) {
        return 0.5 * airDensity * dragArea * pow(velocity, 2.0);
    }
}