#pragma once
#include "../MapLib/map.h"
#include "../CarLib/Car.h"

class Display{
public:
    Display() = default;
    virtual void drawPoint(Position coords, char character) = 0;
};


