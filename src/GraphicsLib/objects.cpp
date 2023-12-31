#include "objects.h"

/*
Autor: Karol Ziarek
*/

void DisplayTile::draw(){
    display.drawPoint(position, character);
}

void DisplayCar::draw(){
    display.drawPoint(position, character);
}

void DisplayLine::draw(){
    Position tmp = position;
    if (axis){       // axis = 1 - horizontal line
        for(int i=0; i<length; i++){
            display.drawPoint(tmp, character);
            tmp.x++;
        }}
    else{            // axis = 0 - vertical line
        for(int i=0; i<length; i++){
            display.drawPoint(tmp, character);
            tmp.y++;
        }}
}

void clearConsole::draw(){
    for(int i=0; i<length; i++){
        for(int j=0; j<height; j++){
            display.drawPoint(Position(i, j), character);
        }
    }
}