#pragma once
#include <iostream>
#include <vector>
#include "../CarLib/Car.h"
#include "../MapLib/Position.h"


class StupidDriver
{
protected:
    Position position;
    std::vector<int> wall_distances;
    char direction;
    int speed;
    int road_quality;
    int temperature;
    int humidity;
    void avoidWall(Car &car) noexcept;

public:
    StupidDriver() noexcept;
    StupidDriver(Car &car);
    void updatePosition(Car &car) noexcept;
    std::vector<int> getWallDistances() const noexcept;
    char getDirection() const noexcept;
    int getSpeed() const noexcept;
    int getTemperature() const noexcept;
    int getRoadQuality() const noexcept;
    int getHumidity() const noexcept;
    virtual void navigate(Car &car) noexcept;
};
