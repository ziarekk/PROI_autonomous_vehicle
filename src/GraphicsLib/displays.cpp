#include "displays.h"

void ConsoleDisplay::setPosition(Coords coords) {
    SetConsoleCursorPosition(out, coords.getCOORD());
}

void ConsoleDisplay::drawPoint(Coords coords, char character) {
    setPosition(coords);
    std::cout<<character;
}
