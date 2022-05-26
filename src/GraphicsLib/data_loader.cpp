#include "data_loader.h"

void dataLoader::load_data() {
    Coords coord;
    char mark;
    for(auto vector: map.getFieldContainer()){
        for(auto field: vector){
            coord.X = field.getLocation().x;
            coord.Y = field.getLocation().y;
            mark = getTexture(field);

            drawing += std::make_unique<DisplayTile>(DisplayTile(coord, display, mark));
        }
    }
    coord.X = car.getLocation().x;
    coord.Y = car.getLocation().y;
    drawing += std::make_unique<DisplayCar>(DisplayCar(coord, display));
}

char dataLoader::getTexture(Field& field){
    if(field.getIsBarrier())
        return 'X';
    else
        return  ' ';
}