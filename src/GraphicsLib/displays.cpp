#include "displays.h"

static HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void ConsoleDisplay::setPosition(Coords coords) {
    SetConsoleCursorPosition(out, coords.getCOORD());
}

void ConsoleDisplay::drawPoint(Coords coords, char character) {
    setPosition(coords);
    std::cout<<character;
}
