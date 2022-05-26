#include "Car.h"
#include "../MapLib/Position.h"

void Steering::setLocation(Position loc) {
    this->location = loc;
}
Position Steering::getLocation() const noexcept{
    return location;
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

Car::Car(Position starting_position, Map world, int acceleration, int max_speed) {
    this->setLocation(starting_position);
    this->setAcceleration(acceleration);
    this->setMaxSpeed(max_speed);
    this->world = world;
}
Car::Car() noexcept {
    Position loc(50, 50);
    this->setLocation(loc);
    this->setAcceleration(4);
    this->setMaxSpeed(20);
}
bool TouchSensor::getInfo(Position location, Map world) noexcept {
    int x = location.x;
    int y = location.y;
    Position loc1(x-1, y);
    if (world(loc1).getIsBarrier() == true)
        return isTouched = true;
    Position loc2(x+1, y);
    if (world(loc2).getIsBarrier() == true)
        return isTouched = true;
    Position loc3(x, y-1);
    if (world(loc3).getIsBarrier() == true)
        return isTouched = true;
    Position loc4(x, y+1);
    if (world(loc4).getIsBarrier() == true)
        return isTouched = true;
    isTouched = false;
    return isTouched;
}
int HumiditySensor::getHumidity(Position location, Map world) noexcept {
    return world(location).getHumidity();
}

int SurfaceSensor::getCondition(Position location, Map world) noexcept {
    return world(location).getSurface_Condition();
}
int RadarSensor::getDistance(Position location, Map world, char direction) {
    int x = location.x;
    int y = location.y;
    if (direction == 'n')
    {
        for (int i = y; i < 99; i++)
        {
            Position loc1(x, i);
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
            Position loc2(i, y);
            if (world(loc2).getIsBarrier() == true)
            {
                return i - x;
            }
        }
        return 99 - x;
    }
    if (direction == 'w')
    {
        for (int i = x; i > 0; i--)
        {
            Position loc3(i, y);
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
            Position loc4(x, i);
            if (world(loc4).getIsBarrier() == true)
            {
                return y - i;
            }
            else
                return y - 0;
        }
    }
}

ThinkingCar::ThinkingCar(Position starting_position, Map world, int acceleration, int max_speed) {
    this->setLocation(starting_position);
    this->setAcceleration(acceleration);
    this->setMaxSpeed(max_speed);
    this->world = world;
}
ThinkingCar::ThinkingCar() noexcept {
    Position loc(50, 50);
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