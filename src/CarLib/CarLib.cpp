#include "Car.h"
#include <thread>
#include <chrono>

Location Steering::getLocation() const noexcept{
    Location loc;
    loc.xLocation = xLocation;
    loc.yLocation = yLocation;
    return loc;
}
int Steering::getSpeed() const noexcept {
    return speed;
}
void Steering::setSpeed(int new_speed) {
    this->speed = new_speed;
}
void Steering::goLeft(int time) {
    if (speed > 0) {
        for (int i = 0; i < time*speed; i++) {
            if (xLocation > 0)
                xLocation--;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/speed));
        }
    }
}
void Steering::goRight(int time) {
    if (speed > 0) {
        for (int i = 0; i < time*speed; i++) {
            if (xLocation < 99)
                xLocation++;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/speed));
        }
    }
}
void Steering::goUp(int time) {
    if (speed > 0) {
        for (int i = 0; i < time*speed; i++) {
            if (yLocation < 99)
                yLocation++;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/speed));
        }
    }
}
void Steering::goDown(int time) {
    if (speed > 0) {
        for (int i = 0; i < time*speed; i++) {
            if (yLocation > 0)
                yLocation--;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/speed));
        }
    }
}

Field::Field(Location location) noexcept {
    this->xLocation = location.xLocation;
    this->yLocation = location.yLocation;
}
Location Field::getLocation() const noexcept {
    Location loc;
    loc.xLocation = xLocation;
    loc.yLocation = yLocation;
    return loc;
}
bool Field::getIsBarrier() const noexcept {
    return isBarrier;
}
void Field::setIsBarrier(bool barrier) {
    this->isBarrier = barrier;
}
int Field::getHumidity() const noexcept {
    return humidity;
}
void Field::setHumidity(int hum) {
    this->humidity = hum;
}
int Field::getSurface_Condition() const noexcept {
    return surface_condition;
}
void Field::setSurface_Condition(int condition) {
    this->surface_condition = condition;
}
int Field::getMinimal_Horsepower() const noexcept {
    return minimal_horsepower;
}
void Field::setMinimal_Horsepower(int HP) {
    this->minimal_horsepower = HP;
}
World::World() noexcept {
    std::vector<std::vector<Field>> outside;
    for (int i = 0; i < 100; i++)
    {
        std::vector<Field> inside;
        for (int j = 0; j < 100; j++)
        {
            Location loc;
            loc.xLocation = i;
            loc.yLocation = j;
            Field field(loc);
            inside.push_back(field);
        }
        outside.push_back(inside);
    }
    field_container = outside;
}
void World::setField(Field square) {
    Location v = square.getLocation();
    field_container[v.xLocation][v.yLocation] = square;
}
std::vector<std::vector<Field>> World::getFieldContainer() const noexcept {
    return field_container;
}
Field World::operator()(Location location) const noexcept {
    return field_container[location.xLocation][location.yLocation];
}

bool TouchSensor::getInfo(Location location, World world) noexcept {
    if (world(location).getIsBarrier() == true)
        isTouched = true;
    return isTouched;
}

int HumiditySensor::getHumidity(Location location, World world) noexcept {
    return world(location).getHumidity();
}

int SurfaceSensor::getCondition(Location location, World world) noexcept {
    return world(location).getSurface_Condition();
}

bool ThinkingCar::getTouchInfo(World world) noexcept {
    return touch.getInfo(this->getLocation(), world);
}
int ThinkingCar::getHumidityInfo(World world) noexcept {
    return humidity.getHumidity(this->getLocation(), world);
}
int ThinkingCar::getSurfaceCondition(World world) noexcept {
    return condition.getCondition(this->getLocation(), world);
}

void Car::setPower(int HP) {
    horsepower = HP;
}

int Car::getPower(int HP) {
    return horsepower;
}

bool Car::isEnoughPower(World world) noexcept {
    Location location = this->getLocation();
    if (world(location).getIsBarrier() == true)
        canDrive = true;
    else
        canDrive = false;
    return canDrive;
}
