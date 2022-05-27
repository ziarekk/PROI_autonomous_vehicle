#pragma once
#include <vector>
#include "../MapLib/map.h"
#include "../MapLib/Position.h"

class Steering
{
private:
    char direction='n';
    Position location;
    int speed=0;
    int maxSpeed=20;
    int acceleration=4;
public:
    void setLocation(Position loc);
    Position getLocation() const noexcept;
    int getSpeed() const noexcept;
    void setMaxSpeed(int max);
    void setAcceleration(int acc);
    char getDirection() const noexcept;
    void accelerate() noexcept;
    void brake() noexcept;
    void turnLeft() noexcept;
    void turnRight() noexcept;
};

class Sensor
{
};

class Car: public Steering
{
private:
    std::vector<Sensor> list_of_sensors;
    Map world;
public:
    Car(Position starting_position, Map world, int acceleration=4, int max_speed=20);
    Car() noexcept;
};

class TouchSensor: public Sensor
{
private:
    bool isTouched;
public:
    bool getInfo(Position location, Map world) noexcept;
};

class HumiditySensor
{
private:
    int humidity;
public:
    int getHumidity(Position location, Map world) noexcept;
};

class SurfaceSensor: public Sensor
{
private:
    int surface_condition;
public:
    int getCondition(Position location, Map world) noexcept;
};

class RadarSensor: public Sensor
{
private:
    int distance;
public:
    int getDistance(Position location, Map world, char direction);
};

class ThinkingCar: public Car
{
private:
    TouchSensor touch;
    HumiditySensor humidity;
    SurfaceSensor condition;
    RadarSensor radar;
    Map &world;
public:
    ThinkingCar(Position starting_position, Map &world, int acceleration=4, int max_speed=20);
    ThinkingCar() noexcept;
    bool getTouchInfo() noexcept;
    int getHumidityInfo() noexcept;
    int getSurfaceCondition() noexcept;
    int getRadarInfo() noexcept;
};
