#pragma once
#include <iostream>
#include <vector>
#include "../CarLib/Car.h"
#include "../MapLib/Position.h"

class Driver
{
protected:
    Position position;
    Position destination;
    std::vector<int> wall_distances;
    char direction;
    int speed;
    int road_quality;
    int temperature;
    int humidity;
    void avoidWall(Car &car) noexcept;
public:
    Driver() noexcept;
    Driver(Position position, int maxSpeed, char direction, Position destination, std::vector<int> distances, std::vector<int> attributes) noexcept;
    void updatePosition(Car &car);
    Position getDestination() const noexcept;
    std::vector<int> getWallDistances() const noexcept;
    char getDirection() const noexcept;
    int getSpeed() const noexcept;
    int getTemperature() const noexcept;
    int getRoadQuality() const noexcept;
    int getHumidity() const noexcept;
    virtual void navigate(Car &car) noexcept;
};
