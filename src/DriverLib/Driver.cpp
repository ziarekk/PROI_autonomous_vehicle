#include <iostream>
#include <vector>
#include "Driver.h"
#include "Car.h"

using namespace std;

Driver::Driver() noexcept {
    this->position = vector<int> {0, 0};
    this->speed = 50;
}

Driver::Driver(vector<int> position, char direction, vector<int> destination, vector<int> distances, vector<int> attributes) noexcept {
    this->position = position;
    this->direction = direction;
    this->destination = destination;
    this->speed = 50;
    this->wall_distances = distances;
    this->road_quality = attributes[0];
    this->temperature = attributes[1];
    this->humidity = attributes[2];
}

void Driver::updatePosition(std::vector<int> new_position, char new_direction, vector<int> new_distances, vector<int> new_attributes) {
    this->position = new_position;
    this->direction = new_direction;
    this->wall_distances = new_distances;
    this->road_quality = new_attributes[0];
    this->temperature = new_attributes[1];
    this->humidity = new_attributes[2];
}

void Driver::avoidWall(Car &car) noexcept {
    int left = this->wall_distances[1];
    int right = this->wall_distances[2];
    if (left > right) {
        car.turnLeft();
    }
    else {
        car.turnRight();
    }
}

void Driver::navigate(Car &car) noexcept {
    if (position == destination) {
        this->speed = 0;
    }
    if (wall_distances[0] < 3) {
        this->avoidWall(car);
    }
    // X positioning
    if (position[0] < destination[0] && direction != 'e') {
        if (direction == 's') {
            car.turnLeft();
        }
        else {
            car.turnRight();
        }
    }
    else if (position[0] > destination[0] && direction != 'w') {
        if (direction == 's') {
            car.turnRight();
        }
        else {
            car.turnLeft();
        }
    }
    // Y positioning
    if (position[1] < destination[1] && direction != 's') {
        if (direction == 'e') {
            car.turnRight();
        }
        else {
            car.turnLeft();
        }
    }
    else if (position[1] > destination[1] && direction != 'n') {
        if (direction == 'w') {
            car.turnRight();
        }
        else {
            car.turnLeft();
        }
    }
}
