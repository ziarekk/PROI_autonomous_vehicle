#include <vector>
#include "../MapLib/map.h"

class Steering
{
private:
    char direction='n';
    int xLocation=49;
    int yLocation=49;
    int speed=0;
    int maxSpeed=20;
    int acceleration=4;
public:
    void setLocation(int const* loc);
    int* getLocation() const noexcept;
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
    World world;
public:
    Car(int* starting_position, World world, int acceleration=4, int max_speed=20);
    Car() noexcept;
};

class TouchSensor: public Sensor
{
private:
    bool isTouched;
public:
    bool getInfo(int* location, World world) noexcept;
};

class HumiditySensor
{
private:
    int humidity;
public:
    int getHumidity(int* location, World world) noexcept;
};

class SurfaceSensor: public Sensor
{
private:
    int surface_condition;
public:
    int getCondition(int* location, World world) noexcept;
};

class RadarSensor: public Sensor
{
private:
    int distance;
public:
    int getDistance(int*location, World world, char direction);
};

class ThinkingCar: public Car
{
private:
    TouchSensor touch;
    HumiditySensor humidity;
    SurfaceSensor condition;
    RadarSensor radar;
    World world;
public:
    ThinkingCar(int* starting_position, World world, int acceleration=4, int max_speed=20);
    ThinkingCar() noexcept;
    bool getTouchInfo() noexcept;
    int getHumidityInfo() noexcept;
    int getSurfaceCondition() noexcept;
    int getRadarInfo() noexcept;
};
