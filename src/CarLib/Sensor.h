#pragma once
#include "../MapLib/map.h"
#include "../MapLib/Position.h"

/*

Autor: Szymon Jankowski

Funkcja getInfo(): Karol Ziarek & Wojciech Łapacz

*/

class Sensor
{
public:
    Sensor() = default;
    virtual int getInfo(Position location, Map& map){
        return 0;
    };
};

class TouchSensor: public Sensor
{
private:
    bool isTouched = false;
public:
    TouchSensor() = default;
    bool getIsTouched(Position location, Map& map);
};

class HumiditySensor: public Sensor
{
private:
    int humidity = 0;
public:
    HumiditySensor() = default;
    int getInfo(Position location, Map& map) override;
};

class SurfaceSensor: public Sensor
{
private:
    int surface_condition = 0;
public:
    SurfaceSensor() = default;
    int getInfo(Position location, Map& map) override;
};

class TemperatureSensor: public Sensor
{
private:
    int temperature=0;
public:
    TemperatureSensor() = default;
    int getInfo(Position location, Map& map) override;
};

class RadarSensor: public Sensor
{
private:
    int distance = 0;
public:
    RadarSensor() = default;
    std::vector<int> getInfo(Position location, Map& map, char direction);
};