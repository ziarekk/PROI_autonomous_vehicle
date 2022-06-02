#include "TerminalDisplay.h"

/*
Autor: Karol Ziarek
*/

void TerminalDisplay::setPosition(Position coords){
        printf("\033[%d;%dH",coords.y+1,coords.x+1);
    }

void TerminalDisplay::drawPoint(Position coords, char character) {
         printf("%c", character);
}