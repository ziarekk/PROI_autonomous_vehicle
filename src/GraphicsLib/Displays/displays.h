#pragma once
#include "map.h"
#include "car.h"

class Display{
public:
    Display() = default;
    virtual void drawPoint(Position coords, char character) = 0;
};


