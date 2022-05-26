#include "graphics.h"

static HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

COORD Coords::getCOORD(){
    COORD point;
    point.X = X; point.Y = Y;
    return point;
}

void Coords::x_up(){
    X++;
}
void Coords::y_up() {
    Y++;
}

