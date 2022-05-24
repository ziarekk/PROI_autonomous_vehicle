#include <iostream>
#include <vector>
#include "IntelligentDriver.h"
#include "../Car.h"

using namespace std;

IntelligentDriver::IntelligentDriver() noexcept {
    this->position = vector<int> {0, 0};
    this->speed = 50;
}

IntelligentDriver::IntelligentDriver(vector<int> position, char direction, vector<int> destination, vector<int> distances, vector<int> attributes) noexcept {
    this->position = position;
    this->direction = direction;
    this->destination = destination;
    this->wall_distances = distances;
    this->road_quality = attributes[0];
    this->temperature = attributes[1];
    this->humidity = attributes[2];
    this->calculateSpeed();
}

void IntelligentDriver::updatePosition(vector<int> new_position, char new_direction, vector<int> new_distances, vector<int> new_attributes) noexcept {
    this->position = new_position;
    this->direction = new_direction;
    this->wall_distances = new_distances;
    this->road_quality = new_attributes[0];
    this->temperature = new_attributes[1];
    this->humidity = new_attributes[2];
    this->calculateSpeed();
}

void IntelligentDriver::navigate(Car &car) noexcept {
    /* ... */
}
