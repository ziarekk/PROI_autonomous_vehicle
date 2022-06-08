#pragma once
#include "displays.h"
#include <windows.h>
#include <iostream>

/*
Autor: Karol Ziarek
*/

class WindowsTerminalDisplay: public Display{
public:
    WindowsTerminalDisplay() = default;
    void setPosition(COORD coords);
    void drawPoint(Position coords, char character) override;
    static COORD ToCOORD(Position position);
    char getTexture(Field& field) override;
};