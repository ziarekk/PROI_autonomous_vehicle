#pragma once
#include <vector>
#include "../MapLib/map.h"
#include "../MapLib/Position.h"
#include "Sensor.h"

class Steering
{
protected:
    char direction;
    int speed=0;
    int maxSpeed=20;
public:
    Steering(char direction='n', int maxSpeed = 20): direction(direction), maxSpeed(maxSpeed) {};
    virtual int getSpeed() const noexcept;
    virtual void setMaxSpeed(int max);
    virtual int getMaxSpeed() const noexcept;
    virtual char getDirection() const noexcept;
    virtual void accelerate(int new_speed);
    virtual void turnLeft() noexcept;
    virtual void turnRight() noexcept;
};

class BaseCar: public Steering
{
protected:
    Position location;
    int maxSpeed=20;
    std::vector<Sensor> list_of_sensors;
public:
    void setLocation(Position loc);
    Position getLocation() const noexcept;
    BaseCar(Position starting_position, char direction='n', int max_speed=20):
            Steering(direction, max_speed), location(starting_position) {};
    BaseCar() noexcept {};
    void move() noexcept;
};

class Car: public BaseCar
{
protected:
    TouchSensor touch;
    TemperatureSensor temp;
    HumiditySensor humidity;
    SurfaceSensor condition;
    RadarSensor radar;
    Map& world;
public:
    Car(Position starting_position, Map &world, char direction='n', int max_speed=20) : BaseCar(starting_position, direction, max_speed), world(world) {};
    bool getTouchInfo() noexcept;
    void setDirection(char dir) noexcept;
    Map& getMapRef();
    int getHumidityInfo() noexcept;
    int getSurfaceCondition() noexcept;
    int getTemperature() noexcept;
    std::vector<int> getRadarInfo() noexcept;
    std::vector<int> getAttributes() noexcept;
};




