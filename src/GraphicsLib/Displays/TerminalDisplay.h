#pragma once
#include "displays.h"
#include <stdio.h>

/*
Autor: Karol Ziarek
*/

class TerminalDisplay: public Display{
public:
    TerminalDisplay() = default;
    void setPosition(Position coords);
    void drawPoint(Position coords, char character) override;
};
