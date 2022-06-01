#pragma once
#include <iostream>
#include <vector>
#include "../StupidDriver/StupidDriver.h"
#include "../CarLib/Car.h"
#include "../MapLib/Position.h"

class Driver : public StupidDriver
{
protected:
    Position destination;
    void avoidWall(Car &car) noexcept;

public:
    Driver() : StupidDriver() {};
    Driver(Car &car, Position destination) : StupidDriver(car) {
        this->destination = destination;
        car.accelerate(this->speed);
    };
    Position getDestination() const noexcept;
    void navigate(Car &car) noexcept;
};
