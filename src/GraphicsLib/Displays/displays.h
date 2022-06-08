#pragma once
#include "../MapLib/map.h"
#include "../CarLib/Car.h"

/*
Autor: Karol Ziarek
*/

class Display{
public:
    Display() = default;
    virtual void drawPoint(Position coords, char character) = 0;
    virtual char  getTexture(Field& field) = 0;
};


