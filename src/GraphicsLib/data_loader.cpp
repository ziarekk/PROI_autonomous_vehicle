#include "data_loader.h"

/*
Autor: Karol Ziarek
*/

void dataLoader::load_data() {
    Position position;
    char mark;
    for(auto& vector: map.getFieldContainer()){
        for(auto field: vector){
            position = field.location;
            mark = display.getTexture(field);

            drawing += std::make_unique<DisplayTile>(DisplayTile(position, display, mark));
        }
    }
    position = car.getLocation();
    drawing += std::make_unique<DisplayCar>(DisplayCar(position, display));
}