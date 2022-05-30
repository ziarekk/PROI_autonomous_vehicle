#pragma once
#include <vector>
#include "../MapLib/map.h"
#include "../MapLib/Position.h"
#include "Sensor.h"

class Steering
{
protected:
    char direction='n';
    int speed=0;
    int maxSpeed=20;
public:
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
    char direction;
    int maxSpeed=20;
    std::vector<Sensor> list_of_sensors;

public:
    void setLocation(Position loc);
    Position getLocation() const noexcept;
    BaseCar(Position starting_position, char direction='n', int max_speed=20) : location(starting_position), direction(direction), maxSpeed(max_speed) {};
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
    char direction;
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




