#include <vector>
#include "Driver.h"
#include "../CarLib/Car.h"
#include "../MapLib/Position.h"

using namespace std;

Driver::Driver() noexcept {
    this->position = Position();
    this->speed = 1;
}

Driver::Driver(Car &car, char direction, Position destination) noexcept {
    vector<int> attributes = car.getAttributes();
    this->position = car.getLocation();
    this->direction = car.getDirection();
    this->destination = destination;
    this->speed = car.getMaxSpeed();
    this->wall_distances = car.getRadarInfo();
    this->road_quality = attributes[0];
    this->temperature = attributes[1];
    this->humidity = attributes[2];
    car.accelerate(this->speed);
}

void Driver::updatePosition(Car &car) {
    vector<int> attributes = car.getAttributes();
    this->position = car.getLocation();
    this->direction = car.getDirection();
    this->wall_distances = car.getRadarInfo();
    this->road_quality = attributes[0];
    this->temperature = attributes[1];
    this->humidity = attributes[2];
    car.accelerate(this->speed);
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
        car.accelerate(this->speed);
        return;
    }
    // avoid obstacle
    if (wall_distances[0] == 1) {
        this->avoidWall(car);
        return;
    }
    // X positioning
    if (position.x < destination.x) {
        if (direction == 's') {
            car.turnLeft();
            return;
        }
        else if (direction != 'e') {
            car.turnRight();
            return;
        }
    }
    else if (position.x > destination.x) {
        if (direction == 's') {
            car.turnRight();
            return;
        }
        else if (direction != 'w') {
            car.turnLeft();
            return;
        }
    }
    // Y positioning
    else if (position.y < destination.y) {
        if (direction == 'e') {
            car.turnRight();
            return;
        }
        else if (direction != 's') {
            car.turnLeft();
            return;
        }
    }
    else if (position.y > destination.y) {
        if (direction == 'w') {
            car.turnRight();
            return;
        }
        else if (direction != 'n') {
            car.turnLeft();
            return;
        }
    }
}