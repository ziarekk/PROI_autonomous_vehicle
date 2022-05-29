#include "Car.h"
#include "../MapLib/Position.h"

int Steering::getSpeed() const noexcept {
    return speed;
}
void Steering::setMaxSpeed(int max) {
    this->maxSpeed = max;
}
int Steering::getMaxSpeed() const noexcept {
    return this->maxSpeed;
}
char Steering::getDirection() const noexcept {
    return direction;
}
void Steering::accelerate(int new_speed) {
    this->speed = std::min(new_speed, maxSpeed);
}
void Steering::turnLeft() noexcept {
    // char directions [4] {'n', 'e', 's', 'w'};
    // for (int i=0; i<3; i++)
    // {
    //     if (directions[i] == direction)
    //     {
    //         i--;
    //         if (i < 0)
    //         {
    //             i=3;
    //         }
    //         direction = directions[i];
    //     }
    // }

    if (direction == 'n') {
        this->direction = 'w';
    }
    else if (direction == 's') {
        this->direction = 'e';
    }
    else if (direction == 'e') {
        this->direction = 'n';
    }
    else if (direction == 'w') {
        this->direction = 's';
    }
}

void Steering::turnRight() noexcept {
    // char directions [4] {'n', 'e', 's', 'w'};
    // for (int i=0; i<3; i++)
    // {
    //     if (directions[i] == direction)
    //     {
    //         i++;
    //         if (i > 3)
    //         {
    //             i=0;
    //         }
    //         direction = directions[i];
    //     }
    // }

    if (direction == 'n') {
        this->direction = 'e';
    }
    else if (direction == 's') {
        this->direction = 'w';
    }
    else if (direction == 'e') {
        this->direction = 's';
    }
    else if (direction == 'w') {
        this->direction = 'n';
    }
}


void BaseCar::setLocation(Position loc) {
    this->location = loc;
}
Position BaseCar::getLocation() const noexcept{
    return location;
}

void BaseCar::move() noexcept {
    if (this->speed == 0) {
        return;
    }
    if (this->direction != 'n' && this->direction != 's') {
        if (this->direction == 'e') {
            this->location.x += 1;
        }
        else {
            this->location.x -= 1;
        }
    }
    else {
        if (this->direction == 'n') {
            this->location.y -= 1;
        }
        else {
            this->location.y += 1;
        }
    }
}



Map& Car::getMapRef() {
    return world;
}
bool Car::getTouchInfo() noexcept {
    return touch.getIsTouched(location, world);
}
int Car::getTemperature() noexcept {
    return temp.getInfo(location, world);
}
int Car::getHumidityInfo() noexcept {
    return humidity.getInfo(location, world);
}
int Car::getSurfaceCondition() noexcept {
    int i = condition.getInfo(location, world);
    return i;
}
std::vector<int> Car::getRadarInfo() noexcept {
    return radar.getInfo(location, world, this->getDirection());
}
std::vector<int> Car::getAttributes() noexcept {
    std::vector<int> attributes;
    attributes.push_back(temp.getInfo(this->getLocation(), world));
    attributes.push_back(humidity.getInfo(this->getLocation(), world));
    attributes.push_back(condition.getInfo(this->getLocation(), world));
    return attributes;
}