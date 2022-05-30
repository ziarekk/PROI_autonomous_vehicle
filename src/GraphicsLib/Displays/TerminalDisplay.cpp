#include "TerminalDisplay.h"

void TerminalDisplay::setPosition(Position coords){
        printf("\033[%d;%dH",coords.y+1,coords.x+1);
    }

void TerminalDisplay::drawPoint(Position coords, char character) {
         printf("\033[%d;%dH",coords.y+1,coords.x+1);
}