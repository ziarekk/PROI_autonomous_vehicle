#include <iostream>
#include "../BaseDriver/Driver.h"

/*
Autor: Wojciech Łapacz
*/

class IntelligentDriver : public Driver
{
public:
    IntelligentDriver() :Driver() {};
    IntelligentDriver(Car &car, Position destination) : Driver(car, destination) {};
    void navigate(Car &car) noexcept {
        // THERE CAN BE IMPORTED A MODULE WITH AI MODEL FOR PREDICTING MOVES
    }
};
