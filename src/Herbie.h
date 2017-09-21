#ifndef HERBIE_H
#define HERBIE_H

class Herbie : public Car {
public:
    Herbie() : Car ("Herbie", 0, 0, 0){};
    void drive(double dt) {
        std::cout << "Herbie just teleported 3000m ahead" << std::endl;
        this->state.set(this->state.position + 3000, 0, 0, 0);
    }
};
#endif
