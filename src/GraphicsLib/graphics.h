#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <memory>
#include "../MapLib/map.h"
#include "../CarLib/car.h"

class Coords{
public:
    SHORT X,Y;
    Coords(): X(0), Y(0){};
    Coords(int X, int Y): X(X), Y(Y) {};
    void x_up();
    void y_up();
    COORD getCOORD();
};

