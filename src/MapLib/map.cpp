#include "map.h"
#include "Position.h"

Map::Map() noexcept {
    for (int i = 0; i < 20; i++)
    {
        std::vector<Field> inside;
        for (int j = 0; j < 20; j++)
        {
            Field field(Position(i, j), false, 60, 10, 20);
            inside.push_back(field);
        }
        field_container.push_back(inside);
    }
}

void Map::setField(Field square) {
    Position v = square.location;
    field_container[v.x][v.y] = square;
}

std::vector<std::vector<Field>> Map::getFieldContainer() const noexcept {
    return field_container;
}
Field Map::operator()(Position location) const noexcept {
    return field_container[location.x][location.y];
}
