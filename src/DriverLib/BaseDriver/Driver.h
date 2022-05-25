#pragma once
#include <iostream>
#include <vector>

template<class C>
class Driver
{
protected:
    std::vector<int> position;
    std::vector<int> destination;
    std::vector<int> wall_distances;
    char direction;
    int speed;
    int road_quality;
    int temperature;
    int humidity;

    void avoidWall(C &car) noexcept {
        int left = this->wall_distances[1];
        int right = this->wall_distances[2];
        if (left > right) {
            car.turnLeft();
        }
        else {
            car.turnRight();
        }
    }

public:
    Driver() noexcept {
        this->position = std::vector<int> {0, 0};
        this->speed = 50;
    }

    Driver(std::vector<int> position, char direction, std::vector<int> destination, std::vector<int> distances, std::vector<int> attributes) noexcept {
        this->position = position;
        this->direction = direction;
        this->destination = destination;
        this->speed = 50;
        this->wall_distances = distances;
        this->road_quality = attributes[0];
        this->temperature = attributes[1];
        this->humidity = attributes[2];
    }

    void updatePosition(std::vector<int> new_position, char new_direction, std::vector<int> new_distances, std::vector<int> new_attributes) {
        this->position = new_position;
        this->direction = new_direction;
        this->wall_distances = new_distances;
        this->road_quality = new_attributes[0];
        this->temperature = new_attributes[1];
        this->humidity = new_attributes[2];
    }

    std::vector<int> getDestination() const noexcept {
        return this->destination;
    }

    std::vector<int> getWallDistances() const noexcept {
        return this->wall_distances;
    }

    char getDirection() const noexcept {
        return this->direction;
    }

    int getSpeed() const noexcept {
        return this->speed;
    }

    int getTemperature() const noexcept {
        return this->temperature;
    }

    int getRoadQuality() const noexcept {
        return this->road_quality;
    }

    int getHumidity() const noexcept {
        return this->humidity;
    }

    void navigate(C &car) noexcept {
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
        if (position[0] < destination[0]) {
            if (direction == 's') {
                car.turnLeft();
            }
            else if (direction != 'e') {
                car.turnRight();
            }
        }
        else if (position[0] > destination[0]) {
            if (direction == 's') {
                car.turnRight();
            }
            else if (direction != 'w') {
                car.turnLeft();
            }
        }
        // Y positioning
        else if (position[1] < destination[1]) {
            if (direction == 'e') {
                car.turnRight();
            }
            else if (direction != 's') {
                car.turnLeft();
            }
        }
        else if (position[1] > destination[1]) {
            if (direction == 'w') {
                car.turnRight();
            }
            else if (direction != 'n') {
                car.turnLeft();
            }
        }
    }
};
