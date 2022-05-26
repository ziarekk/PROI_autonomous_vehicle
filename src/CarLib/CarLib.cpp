#include "Car.h"

void Steering::setLocation(int const* loc) {
    xLocation = loc[0];
    yLocation = loc[1];
}
int* Steering::getLocation() const noexcept{
    int *loc = new int [2] {xLocation, yLocation};
    return loc;
}
int Steering::getSpeed() const noexcept {
    return speed;
}
void Steering::setMaxSpeed(int max) {
    this->maxSpeed = max;
}
void Steering::setAcceleration(int acc) {
    this->acceleration = acc;
}
char Steering::getDirection() const noexcept {
    return direction;
}
void Steering::accelerate() noexcept {

    this->speed = std::min(speed+acceleration, maxSpeed);
}
void Steering::brake() noexcept {
    this->speed = 0;
}
void Steering::turnLeft() noexcept {
    char directions [4] {'n', 'e', 's', 'w'};
    for (int i=0; i<3; i++)
    {
        if (directions[i] == direction)
        {
            i--;
            if (i < 0)
            {
                i=3;
            }
            direction = directions[i];
        }
    }
}
void Steering::turnRight() noexcept {
    char directions [4] {'n', 'e', 's', 'w'};
    for (int i=0; i<3; i++)
    {
        if (directions[i] == direction)
        {
            i++;
            if (i > 3)
            {
                i=0;
            }
            direction = directions[i];
        }
    }
}

Car::Car(int *starting_position, World world, int acceleration, int max_speed) {
    this->setLocation(starting_position);
    this->setAcceleration(acceleration);
    this->setMaxSpeed(max_speed);
    this->world = world;
}
Car::Car() noexcept {
    int loc[2] {50, 50};
    this->setLocation(loc);
    this->setAcceleration(4);
    this->setMaxSpeed(20);
}
bool TouchSensor::getInfo(int* location, World world) noexcept {
    int x = location[0]; int y = location[1];
    int loc1[2] {x-1, y};
    if (world(loc1).getIsBarrier() == true)
        return isTouched = true;
    int loc2[2] {x+1, y};
    if (world(loc2).getIsBarrier() == true)
        return isTouched = true;
    int loc3[2] {x, y-1};
    if (world(loc3).getIsBarrier() == true)
        return isTouched = true;
    int loc4[2] {x, y+1};
    if (world(loc4).getIsBarrier() == true)
        return isTouched = true;
    isTouched = false;
    return isTouched;
}
int HumiditySensor::getHumidity(int* location, World world) noexcept {
    return world(location).getHumidity();
}

int SurfaceSensor::getCondition(int* location, World world) noexcept {
    return world(location).getSurface_Condition();
}
int RadarSensor::getDistance(int *location, World world, char direction) {
    int x = location[0]; int y = location[1];
    if (direction == 'n')
    {
        for (int i=y;i<99;i++)
        {
            int loc1[2] {x, i};
            if (world(loc1).getIsBarrier() == true)
            {
                return i - y;
            }
        }
        return 99 - y;
    }
    if (direction == 'e')
    {
        for (int i=x;i<99;i++)
        {
            int loc2[2] {i, y};
            if (world(loc2).getIsBarrier() == true)
            {
                return i - x;
            }
        }
        return 99 - x;
    }
    if (direction == 'w')
    {
        for (int i=x;i>0;i--)
        {
            int loc3[2] {i, y};
            if (world(loc3).getIsBarrier() == true)
            {
                return x - i;
            }
        }
        return x - 0;
    }
    if (direction == 's')
    {
        for (int i=y;y>0;i--)
        {
            int loc4[2] {x, i};
            if (world(loc4).getIsBarrier() == true)
            {
                return y - i;
            }
            else
                return y - 0;
        }
    }
}

ThinkingCar::ThinkingCar(int *starting_position, World world, int acceleration, int max_speed) {
    this->setLocation(starting_position);
    this->setAcceleration(acceleration);
    this->setMaxSpeed(max_speed);
    this->world = world;
}
ThinkingCar::ThinkingCar() noexcept {
    int loc[2] {50, 50};
    this->setLocation(loc);
    this->setAcceleration(4);
    this->setMaxSpeed(20);
}
bool ThinkingCar::getTouchInfo() noexcept {
    return touch.getInfo(this->getLocation(), world);
}
int ThinkingCar::getHumidityInfo() noexcept {
    return humidity.getHumidity(this->getLocation(), world);
}
int ThinkingCar::getSurfaceCondition() noexcept {
    return condition.getCondition(this->getLocation(), world);
}
int ThinkingCar::getRadarInfo() noexcept {
    return radar.getDistance(this->getLocation(), world, this->getDirection());
}