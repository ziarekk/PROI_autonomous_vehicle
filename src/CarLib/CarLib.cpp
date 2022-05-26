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
Field::Field(int* location) noexcept {
    this->xLocation = location[0];
    this->yLocation = location[1];
}
int* Field::getLocation() const noexcept {
    int *loc = new int[2];
    loc[0] = xLocation;
    loc[1] = yLocation;
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
World::World() noexcept {
    std::vector<std::vector<Field>> outside;
    for (int i = 0; i < 100; i++)
    {
        std::vector<Field> inside;
        for (int j = 0; j < 100; j++)
        {
            int loc[2];
            loc[0] = i;
            loc[1] = j;
            Field field(loc);
            inside.push_back(field);
        }
        outside.push_back(inside);
    }
    field_container = outside;
}
void World::setField(Field square) {
    int* v = square.getLocation();
    field_container[v[0]][v[1]] = square;
}
std::vector<std::vector<Field>> World::getFieldContainer() const noexcept {
    return field_container;
}
Field World::operator()(int* location) const noexcept {
    return field_container[location[0]][location[1]];
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