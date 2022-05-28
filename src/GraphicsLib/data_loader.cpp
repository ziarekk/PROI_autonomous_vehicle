#include "data_loader.h"

void dataLoader::load_data() {
    Position position;
    char mark;
    for(auto& vector: map.getFieldContainer()){
        for(auto field: vector){
            position = field.location;
            mark = getTexture(field);

            drawing += std::make_unique<DisplayTile>(DisplayTile(position, display, mark));
        }
    }
    position = car.getLocation();
    drawing += std::make_unique<DisplayCar>(DisplayCar(position, display));
}

char dataLoader::getTexture(Field& field){
    if(field.isBarrier)
        return 'X';
    else
        return  ' ';
}