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
    int maxSpeed=20;
    std::vector<Sensor> list_of_sensors;

public:
    void setLocation(Position loc);
    Position getLocation() const noexcept;
    BaseCar(Position starting_position, int max_speed=20) : location(starting_position), maxSpeed(max_speed) {};
    BaseCar() noexcept {};
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
    Car(Position starting_position, Map &world, int max_speed=20) : BaseCar(starting_position, max_speed), world(world) {};
    bool getTouchInfo() noexcept;
    Map& getMapRef();
    int getHumidityInfo() noexcept;
    int getSurfaceCondition() noexcept;
    int getTemperature() noexcept;
    std::vector<int> getRadarInfo() noexcept;
    std::vector<int> getAttributes() noexcept;
};




