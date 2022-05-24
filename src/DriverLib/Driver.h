#pragma once
#include <iostream>
#include <vector>
#include "Car.h"

class Driver
{
protected:
    std::vector<int> position;
    std::vector<int> destination;
    std::vector<int> wall_distances;
    char direction;
    int speed;
    int road_quality;
    int temperature;
    int humidity;
    void avoidWall(Car &car) noexcept;
public:
    Driver() noexcept;
    Driver(std::vector<int> position, char direction, std::vector<int> destination, std::vector<int> distances, std::vector<int> attributes) noexcept;
    void updatePosition(std::vector<int> new_position, char new_direction, std::vector<int> new_distances, std::vector<int> new_attributes);
    void navigate(Car &car) noexcept;
};
