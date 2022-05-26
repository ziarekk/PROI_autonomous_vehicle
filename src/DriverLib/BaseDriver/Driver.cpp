#include <vector>
#include "Driver.h"
#include "../CarLib/Car.h"
#include "../MapLib/Position.h"

using namespace std;

Driver::Driver() noexcept {
    this->position = Position();
    this->speed = 50;
}

Driver::Driver(Position position, char direction, Position destination, vector<int> distances, vector<int> attributes) noexcept {
    this->position = position;
    this->direction = direction;
    this->destination = destination;
    this->speed = 50;
    this->wall_distances = distances;
    this->road_quality = attributes[0];
    this->temperature = attributes[1];
    this->humidity = attributes[2];
}

void Driver::updatePosition(Position new_position, char new_direction, std::vector<int> new_distances, std::vector<int> new_attributes) {
    this->position = new_position;
    this->direction = new_direction;
    this->wall_distances = new_distances;
    this->road_quality = new_attributes[0];
    this->temperature = new_attributes[1];
    this->humidity = new_attributes[2];
}

Position Driver::getDestination() const noexcept {
    return this->destination;
}

vector<int> Driver::getWallDistances() const noexcept {
    return this->wall_distances;
}

char Driver::getDirection() const noexcept {
    return this->direction;
}

int Driver::getSpeed() const noexcept {
    return this->speed;
}

int Driver::getTemperature() const noexcept {
    return this->temperature;
}

int Driver::getRoadQuality() const noexcept {
    return this->road_quality;
}

int Driver::getHumidity() const noexcept {
    return this->humidity;
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
    // destination reached
    if (position == destination) {
        this->speed = 0;
        return;
    }
    // avoid obstacle
    if (wall_distances[0] < 3) {
        this->avoidWall(car);
        return;
    }
    // X positioning
    if (position.x < destination.x) {
        if (direction == 's') {
            car.turnLeft();
        }
        else if (direction != 'e') {
            car.turnRight();
        }
    }
    else if (position.x > destination.x) {
        if (direction == 's') {
            car.turnRight();
        }
        else if (direction != 'w') {
            car.turnLeft();
        }
    }
    // Y positioning
    else if (position.y < destination.y) {
        if (direction == 'e') {
            car.turnRight();
        }
        else if (direction != 's') {
            car.turnLeft();
        }
    }
    else if (position.y > destination.y) {
        if (direction == 'w') {
            car.turnRight();
        }
        else if (direction != 'n') {
            car.turnLeft();
        }
    }
}