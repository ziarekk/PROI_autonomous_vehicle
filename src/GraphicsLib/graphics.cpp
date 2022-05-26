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

void ConsoleDisplay::setPosition(Coords coords) {
    SetConsoleCursorPosition(out, coords.getCOORD());
}

void ConsoleDisplay::drawPoint(Coords coords, char character) {
    setPosition(coords);
    std::cout<<character;
}

void DisplayCar::draw(){
    display.drawPoint(coords, character);
}

void DisplayLine::draw(){
    Coords tmp = coords;
    if (axis){       // axis = 1 - horizontal line
        for(int i=0; i<length; i++){
            display.drawPoint(tmp, character);
            tmp.x_up();
        }}
    else{            // axis = 0 - vertical line
        for(int i=0; i<length; i++){
            display.drawPoint(tmp, character);
            tmp.y_up();
        }}
}

