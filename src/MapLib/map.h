#pragma once
#include <vector>
#include "Position.h"

class Field
{
private:
    Position location;
    bool isBarrier=false;
    int humidity;
    int surface_condition;
public:
    Field() noexcept;
    Field(Position location) noexcept;
    Position getLocation() const noexcept;
    bool getIsBarrier() const noexcept;
    void setIsBarrier(bool barrier);
    int getHumidity() const noexcept;
    void setHumidity(int hum);
    int getSurface_Condition() const noexcept;
    void setSurface_Condition(int condition);
};

class Map
{
private:
    std::vector<std::vector<Field>> field_container;
public:
    Map() noexcept;
    void setField(Field square);
    std::vector<std::vector<Field>> getFieldContainer() const noexcept;
    Field operator()(Position location) const noexcept;
};
