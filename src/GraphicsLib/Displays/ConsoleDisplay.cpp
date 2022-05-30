#include "ConsoleDisplay.h"


static HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void ConsoleDisplay::setPosition(COORD coords) {
    SetConsoleCursorPosition(out, coords);
}

void ConsoleDisplay::drawPoint(Position position, char character) {

    setPosition(ToCOORD(position));
    std::cout<<character;
}

COORD ConsoleDisplay::ToCOORD(Position position){
    COORD newCoord;
    newCoord.X = SHORT(position.x);
    newCoord.Y = SHORT(position.y);
    return newCoord;
}