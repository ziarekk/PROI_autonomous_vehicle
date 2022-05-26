#include <iostream>
#include <vector>
#include "SafeDriver.h"
#include "../CarExample/Position.h"

using namespace std;

SafeDriver::SafeDriver() noexcept {
    this->position = Position();
    this->speed = 50;
}

SafeDriver::SafeDriver(Position position, char direction, Position destination, vector<int> distances, vector<int> attributes) noexcept {
    this->position = position;
    this->direction = direction;
    this->destination = destination;
    this->wall_distances = distances;
    this->road_quality = attributes[0];
    this->temperature = attributes[1];
    this->humidity = attributes[2];
    this->calculateSpeed();
}

void SafeDriver::updatePosition(Position new_position, char new_direction, vector<int> new_distances, vector<int> new_attributes) noexcept {
    this->position = new_position;
    this->direction = new_direction;
    this->wall_distances = new_distances;
    this->road_quality = new_attributes[0];
    this->temperature = new_attributes[1];
    this->humidity = new_attributes[2];
    this->calculateSpeed();
}

void SafeDriver::calculateSpeed() noexcept {
    int actual = 150;
    if (road_quality < 5) {
        actual /= 2;
    }
    if (temperature == 0) {
        actual *= 0.9;
    }
    else if (temperature < 0) {
        actual *= 0.7;
    }
    if (humidity > 80 && actual > 50) {
        actual *= 0.8;
    }
    else if (humidity > 90) {
        actual *= 0.7;
    }
    this->speed = actual;
}
