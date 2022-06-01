#include <vector>
#include "Driver.h"
#include "../CarLib/Car.h"
#include "../MapLib/Position.h"

using namespace std;

Position Driver::getDestination() const noexcept {
    return this->destination;
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
        if (direction == 's' && wall_distances[1] > 1) {
            car.turnLeft();
        }
        else if (direction != 'e' && wall_distances[2] > 1) {
            car.turnRight();
        }
    }
    else if (position.x > destination.x) {
        if (direction == 's' && wall_distances[2] > 1) {
            car.turnRight();
        }
        else if (direction != 'w' && wall_distances[1] > 1) {
            car.turnLeft();
        }
    }
    // Y positioning
    else if (position.y < destination.y) {
        if (direction == 'e' && wall_distances[2] > 1) {
            car.turnRight();
        }
        else if (direction != 's' && wall_distances[1] > 1) {
            car.turnLeft();
        }
    }
    else if (position.y > destination.y) {
        if (direction == 'w' && wall_distances[2] > 1) {
            car.turnRight();
        }
        else if (direction != 'n' && wall_distances[1] > 1) {
            car.turnLeft();
        }
    }
}
