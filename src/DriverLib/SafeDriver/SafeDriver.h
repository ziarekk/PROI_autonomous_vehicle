#pragma once
#include <iostream>
#include <vector>
#include "../BaseDriver/Driver.h"

class SafeDriver : public Driver
{
protected:
    void calculateSpeed() noexcept;
public:
    SafeDriver() noexcept;
    SafeDriver(std::vector<int> position, char direction, std::vector<int> destination, std::vector<int> distances, std::vector<int> attributes) noexcept;
    void updatePosition(std::vector<int> new_position, char new_direction, std::vector<int> new_distances, std::vector<int> new_attributes) noexcept;
};
