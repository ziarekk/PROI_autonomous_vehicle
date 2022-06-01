#include <iostream>
#include <vector>
#include "SafeDriver.h"
#include "../MapLib/Position.h"

using namespace std;

void SafeDriver::updatePosition(Car &car) noexcept {
    vector<int> attributes = car.getAttributes();
    this->position = car.getLocation();
    this->direction = car.getDirection();
    this->wall_distances = car.getRadarInfo();
    this->speed = car.getMaxSpeed();
    this->road_quality = attributes[0];
    this->temperature = attributes[1];
    this->humidity = attributes[2];
    this->calculateSpeed(car);
}

void SafeDriver::calculateSpeed(Car &car) noexcept {
    if (road_quality < 5) {
        this->speed /= 2;
    }
    if (temperature == 0) {
        this->speed *= 0.9;
    }
    else if (temperature < 0) {
        this->speed *= 0.7;
    }
    if (humidity > 80 && humidity <= 90) {
        this->speed *= 0.8;
    }
    else if (humidity > 90) {
        this->speed *= 0.6;
    }
    car.accelerate(this->speed);
}
