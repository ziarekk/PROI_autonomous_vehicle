#include "objects.h"

void DisplayTile::draw(){
    display.drawPoint(coords, character);
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

