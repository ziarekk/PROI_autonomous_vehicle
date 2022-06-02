#include <vector>
#include "StupidDriver.h"
#include "../CarLib/Car.h"
#include "../MapLib/Position.h"

/*
Autor: Wojciech Łapacz
*/

using namespace std;

StupidDriver::StupidDriver() noexcept {
    this->position = Position();
    this->speed = 1;
}

StupidDriver::StupidDriver(Car &car) {
    vector<int> attributes = car.getAttributes();
    this->position = car.getLocation();
    this->direction = car.getDirection();
    this->speed = car.getMaxSpeed();
    this->wall_distances = car.getRadarInfo();
    this->road_quality = attributes[0];
    this->temperature = attributes[1];
    this->humidity = attributes[2];
}

void StupidDriver::updatePosition(Car &car) noexcept {
    vector<int> attributes = car.getAttributes();
    this->position = car.getLocation();
    this->direction = car.getDirection();
    this->wall_distances = car.getRadarInfo();
    this->road_quality = attributes[0];
    this->temperature = attributes[1];
    this->humidity = attributes[2];
    car.accelerate(this->speed);
}

vector<int> StupidDriver::getWallDistances() const noexcept {
    return this->wall_distances;
}

char StupidDriver::getDirection() const noexcept {
    return this->direction;
}

int StupidDriver::getSpeed() const noexcept {
    return this->speed;
}

int StupidDriver::getTemperature() const noexcept {
    return this->temperature;
}

int StupidDriver::getRoadQuality() const noexcept {
    return this->road_quality;
}

int StupidDriver::getHumidity() const noexcept {
    return this->humidity;
}

void StupidDriver::avoidWall(Car &car) noexcept {
    int left = this->wall_distances[1];
    int right = this->wall_distances[2];
    if (left > right) {
        car.turnLeft();
    }
    else {
        car.turnRight();
    }
}

void StupidDriver::navigate(Car &car) noexcept {
    car.accelerate(this->speed);
    if (wall_distances[0] == 1) {
        this->avoidWall(car);
    }
}
