#pragma once
#include <iostream>
#include <vector>
#include "../BaseDriver/Driver.h"
#include "../MapLib/Position.h"

/*
Autor: Wojciech Łapacz
*/

class SafeDriver : public Driver
{
protected:
    void calculateSpeed(Car &car) noexcept;
public:
    SafeDriver() : Driver() {};
    SafeDriver(Car &car, Position destination) : Driver(car, destination) {
        this->calculateSpeed(car);
        car.accelerate(this->speed);
    };
    void updatePosition(Car &car) noexcept;
};
