#include "WindowsTerminalDisplay.h"

/*
Autor: Karol Ziarek
*/

static HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void WindowsTerminalDisplay::setPosition(COORD coords) {
    SetConsoleCursorPosition(out, coords);
}

void WindowsTerminalDisplay::drawPoint(Position position, char character) {

    setPosition(ToCOORD(position));
    std::cout<<character;
}

COORD WindowsTerminalDisplay::ToCOORD(Position position){
    COORD newCoord;
    newCoord.X = SHORT(position.x);
    newCoord.Y = SHORT(position.y);
    return newCoord;
}

char WindowsTerminalDisplay::getTexture(Field &field) {
        if(field.isBarrier)
            return 'X';
        else
            return  ' ';
}