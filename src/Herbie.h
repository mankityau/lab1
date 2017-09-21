#ifndef HERBIE_H
#define HERBIE_H

class Herbie : public Car {
public:
    Herbie() : Car ("Herbie", 0, 0, 0){};
    void drive(double dt) {
        //HERBIE is a broken car.
    }
};
#endif
