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
    Map() noexcept;
    void setField(Field square);
    void setFieldContainer(std::vector<std::vector<Field>> new_map);
    std::vector<std::vector<Field>> getFieldContainer() const noexcept;
    Field operator()(Position location) const noexcept;
};

std::vector<std::vector<Field>> read_to_map(std::string fileName);