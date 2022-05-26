#pragma once
#include <iostream>
#include <vector>
#include "../BaseDriver/Driver.h"
#include "../MapLib/Position.h"

class SafeDriver : public Driver
{
protected:
    void calculateSpeed() noexcept;
public:
    SafeDriver() noexcept;
    SafeDriver(Position position, char direction, Position destination, std::vector<int> distances, std::vector<int> attributes) noexcept;
    void updatePosition(Position new_position, char new_direction, std::vector<int> new_distances, std::vector<int> new_attributes) noexcept;
};
