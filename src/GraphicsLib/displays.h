#pragma once
#include "graphics.h"


class Display{
public:
    Display() = default;
    virtual void drawPoint(Coords coords, char character) = 0;
};

class ConsoleDisplay: public Display{
public:
    ConsoleDisplay() = default;
    void setPosition(Coords coords);
    void drawPoint(Coords coords, char character) override;
};

