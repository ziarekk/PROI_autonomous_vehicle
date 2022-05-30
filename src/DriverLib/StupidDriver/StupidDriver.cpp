#include <vector>
#include "StupidDriver.h"
#include "../CarLib/Car.h"
#include "../MapLib/Position.h"

using namespace std;

StupidDriver::StupidDriver(Car &car) noexcept {
    vector<int> attributes = car.getAttributes();
    this->position = car.getLocation();
    this->direction = car.getDirection();
    this->speed = car.getMaxSpeed();
    this->wall_distances = car.getRadarInfo();
    this->road_quality = attributes[0];
    this->temperature = attributes[1];
    this->humidity = attributes[2];
    car.accelerate(this->speed);
}

void StupidDriver::navigate(Car &car) noexcept {
    if (wall_distances[0] == 1) {
        this->avoidWall(car);
    }
}
