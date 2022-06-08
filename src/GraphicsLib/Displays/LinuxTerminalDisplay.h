#pragma once
#include "displays.h"
#include <stdio.h>

/*
Autor: Karol Ziarek
*/

class LinuxTerminalDisplay: public Display{
public:
    LinuxTerminalDisplay() = default;
    void setPosition(Position coords);
    void drawPoint(Position coords, char character) override;
    char getTexture(Field& field) override;
};
