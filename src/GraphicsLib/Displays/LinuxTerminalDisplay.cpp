#include "LinuxTerminalDisplay.h"

/*
Autor: Karol Ziarek
*/

void LinuxTerminalDisplay::setPosition(Position coords){
        printf("\033[%d;%dH",coords.y+1,coords.x+1);
    }

void LinuxTerminalDisplay::drawPoint(Position coords, char character) {
         printf("%c", character);
}

char LinuxTerminalDisplay::getTexture(Field &field) {
    if(field.isBarrier)
        return 'X';
    else
        return  ' ';
}