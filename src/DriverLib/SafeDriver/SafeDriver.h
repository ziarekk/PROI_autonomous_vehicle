#pragma once
#include <iostream>
#include <vector>
#include "../BaseDriver/Driver.h"
#include "../MapLib/Position.h"

class SafeDriver : public Driver
{
protected:
    void calculateSpeed(Car &car) noexcept;
public:
    SafeDriver() noexcept;
    SafeDriver(Car &car, Position destination) noexcept;
    void updatePosition(Car &car) noexcept;
};
