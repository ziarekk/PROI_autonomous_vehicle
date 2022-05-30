#pragma once
#include <vector>
#include "Position.h"
#include <string>

class Field
{
public:
    Position location;
    bool isBarrier;
    int humidity;
    int surface_condition;
    int temperature;

    Field(Position location,  bool isBarrier,  int humidity, int surface_condition, int temperature):
            location(location), isBarrier(isBarrier), humidity(humidity), surface_condition(surface_condition),
            temperature(temperature){};

};

class Map
{
private:
    std::vector<std::vector<Field>> field_container;
public:
    Map() = default;
    Map(int width, int height);
    Map(std::string fileName);
    void setField(Field square);
    void setFieldContainer(std::vector<std::vector<Field>> new_map);
    std::vector<std::vector<Field>> getFieldContainer() const noexcept;
    Field operator()(Position location) const noexcept;
    void read_from_file(std::string fileName);
};
