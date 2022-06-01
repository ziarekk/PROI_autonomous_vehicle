#pragma once
#include "displays.h"
#include <windows.h>
#include <iostream>


class ConsoleDisplay: public Display{
public:
    ConsoleDisplay() = default;
    void setPosition(COORD coords);
    void drawPoint(Position coords, char character) override;
    static COORD ToCOORD(Position position);

};