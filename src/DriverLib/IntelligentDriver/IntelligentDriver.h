#pragma once
#include <iostream>
#include <vector>
#include "../SafeDriver/SafeDriver.h"
#include "../Car.h"

class IntelligentDriver : public SafeDriver
{
public:
    IntelligentDriver() noexcept;
    IntelligentDriver(vector<int> position, char direction, vector<int> destination, vector<int> distances, vector<int> attributes) noexcept;
    void updatePosition(vector<int> new_position, char new_direction, vector<int> new_distances, vector<int> new_attributes) noexcept;
    void navigate(Car &car) noexcept;
};
