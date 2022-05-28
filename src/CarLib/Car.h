#pragma once
#include <vector>
#include "../MapLib/map.h"
#include "../MapLib/Position.h"

class Steering
{
private:
    char direction='n';
    int speed=0;
    int maxSpeed=20;
public:
    int getSpeed() const noexcept;
    void setMaxSpeed(int max);
    int getMaxSpeed() const noexcept;
    char getDirection() const noexcept;
    void accelerate(int new_speed);
    void brake() noexcept;
    void turnLeft() noexcept;
    void turnRight() noexcept;
};

class Sensor
{
};

class Car: public Steering
{
protected:
    Position location;
    int maxSpeed=20;
private:
    std::vector<Sensor> list_of_sensors;
public:
    void setLocation(Position loc);
    Position getLocation() const noexcept;
    Car(Position starting_position, int max_speed=20) : location(starting_position), maxSpeed(max_speed) {};
    Car() noexcept {};
};

class TouchSensor: public Sensor
{
private:
    bool isTouched;
public:
    bool getIsTouched(Position location, Map& world) noexcept;
};

class HumiditySensor
{
private:
    int humidity;
public:
    int getInfo(Position location, Map& world) noexcept;
};

class SurfaceSensor: public Sensor
{
private:
    int surface_condition;
public:
    int getInfo(Position location, Map& world) noexcept;
};

class TemperatureSensor: public Sensor
{
private:
    int temperature;
public:
    int getInfo(Position location, Map& world) noexcept;
};

class RadarSensor: public Sensor
{
private:
    int distance;
public:
    std::vector<int> getInfo(Position location, Map& world, char direction);
};

class ThinkingCar: public Car
{
private:
    TouchSensor touch;
    TemperatureSensor temp;
    HumiditySensor humidity;
    SurfaceSensor condition;
    RadarSensor radar;
    Map& world;
public:
    ThinkingCar(Position starting_position, Map &world, int max_speed=20) : Car(starting_position, max_speed), world(world) {};
    bool getTouchInfo() noexcept;
    Map& getMapRef();
    int getHumidityInfo() noexcept;
    int getSurfaceCondition() noexcept;
    int getTemperature() noexcept;
    std::vector<int> getRadarInfo() noexcept;
    std::vector<int> getAttributes() noexcept;
};
