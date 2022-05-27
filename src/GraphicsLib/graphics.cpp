#include "graphics.h"

COORD Coords::getCOORD(){
    COORD point;
    point.X = SHORT(X); point.Y = SHORT(Y);
    return point;
}

void Coords::x_up(){
    X++;
}
void Coords::y_up() {
    Y++;
}

