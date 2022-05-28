#include "Car.h"
#include "../MapLib/Position.h"

void Car::setLocation(Position loc) {
    this->location = loc;
}
Position Car::getLocation() const noexcept{
    return location;
}
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

bool TouchSensor::getIsTouched(Position location, Map& world) noexcept {
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
int HumiditySensor::getInfo(Position location, Map& world) noexcept {
    return world(location).getHumidity();
}

int TemperatureSensor::getInfo(Position location, Map& world) noexcept {
    return world(location).getTemperature();
}

int SurfaceSensor::getInfo(Position location, Map& world) noexcept {
    Field temp = world.getField(location);
    return temp.getSurface_Condition();
}
std::vector<int> RadarSensor::getInfo(Position location, Map& world, char direction) {
    int x = location.x;
    int y = location.y;
    int front, left, right;
    if (direction == 'n')
    {
        for (int i = y; i < world.getFieldContainer().size(); i++)
        {
            Position loc1(x, i);
            if (world(loc1).getIsBarrier() == true)
            {
                front = i - y;
                break;
            }
        }
        if (front=0)
            front = world.getFieldContainer().size() - y;
        for (int i = x; i > 0; i--)
        {
            Position loc3(i, y);
            if (world(loc3).getIsBarrier() == true)
            {
                left = x - i;
                break;
            }
        }
        if (left=0)
            left = x - 0;
        for (int i=x;i<world.getFieldContainer().size();i++)
        {
            Position loc2(i, y);
            if (world(loc2).getIsBarrier() == true)
            {
                right = i - x;
                break;
            }
        }
        if (right=0)
            right = world.getFieldContainer().size() - x;
    }
    if (direction == 'e')
    {
        for (int i=x;i<world.getFieldContainer().size();i++)
        {
            Position loc2(i, y);
            if (world(loc2).getIsBarrier() == true)
            {
                front = i - x;
                break;
            }
        }
        if (front=0)
            front = world.getFieldContainer().size() - x;
        for (int i = y; i < world.getFieldContainer().size(); i++)
        {
            Position loc1(x, i);
            if (world(loc1).getIsBarrier() == true)
            {
                left = i - y;
                break;
            }
        }
        if (left=0)
            left = world.getFieldContainer().size() - y;
    }
    if (direction == 'w')
    {
        for (int i = x; i > 0; i--) {
            Position loc3(i, y);
            if (world(loc3).getIsBarrier() == true) {
                front = x - i;
                break;
            }
        }
        if (front=0)
            front = x - 0;
        for (int i=y;y>0;i--)
        {
            Position loc4(x, i);
            if (world(loc4).getIsBarrier() == true)
            {
                left = y - i;
                break;
            }
        }
        if (left=0)
            left = y;
        for (int i = y; i < world.getFieldContainer().size(); i++)
        {
            Position loc1(x, i);
            if (world(loc1).getIsBarrier() == true)
            {
                right = i - y;
                break;
            }
        }
        if (right=0)
            right = world.getFieldContainer().size() - y;
    }
    if (direction == 's')
    {
        for (int i=y;y>0;i--)
        {
            Position loc4(x, i);
            if (world(loc4).getIsBarrier() == true)
            {
                front = y - i;
                break;
            }
        }
        if (front=0)
            front = y - 0;
        for (int i=x;i<world.getFieldContainer().size();i++)
        {
            Position loc2(i, y);
            if (world(loc2).getIsBarrier() == true)
            {
                left = i - x;
                break;
            }
        }
        if (left=0)
            left = world.getFieldContainer().size() - x;
        for (int i = x; i > 0; i--)
        {
            Position loc3(i, y);
            if (world(loc3).getIsBarrier() == true)
            {
                right = x - i;
                break;
            }
        }
        if (right=0)
            right = x - 0;

    }
    std::vector<int> distances;
    distances.push_back(front);
    distances.push_back(left);
    distances.push_back(right);
    return distances;
}
Map& ThinkingCar::getMapRef() {
    return world;
}

bool ThinkingCar::getTouchInfo() noexcept {
    return touch.getIsTouched(location, world);
}
int ThinkingCar::getTemperature() noexcept {
    return temp.getInfo(location, world);
}
int ThinkingCar::getHumidityInfo() noexcept {
    return humidity.getInfo(location, world);
}
int ThinkingCar::getSurfaceCondition() noexcept {
    int i = condition.getInfo(location, world);
    return i;
}

std::vector<int> ThinkingCar::getRadarInfo() noexcept {
    return radar.getInfo(location, world, this->getDirection());
}
std::vector<int> ThinkingCar::getAttributes() noexcept {
    std::vector<int> attributes;
    attributes.push_back(temp.getInfo(this->getLocation(), world));
    attributes.push_back(humidity.getInfo(this->getLocation(), world));
    attributes.push_back(condition.getInfo(this->getLocation(), world));
    return attributes;
}