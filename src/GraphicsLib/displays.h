#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <memory>
#include "../MapLib/map.h"
#include "../CarLib/car.h"

class Display{
public:
    Display() = default;
    virtual void drawPoint(Position coords, char character) = 0;
};

class ConsoleDisplay: public Display{
public:
    ConsoleDisplay() = default;
    void setPosition(COORD coords);
    void drawPoint(Position coords, char character) override;
    static COORD ToCOORD(Position position);
};

