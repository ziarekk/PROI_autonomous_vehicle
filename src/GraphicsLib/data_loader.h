#pragma once
#include "drawing.h"


class dataLoader {
private:
    Display& display;
    Map& map;
    Drawing& drawing;
    Car& car;
public:
    dataLoader(Drawing& drawing, Display& display, Map& map, Car& car ):
            drawing(drawing), display(display), map(map), car(car) {};

    void load_data();
    char getTexture(Field& field);
};