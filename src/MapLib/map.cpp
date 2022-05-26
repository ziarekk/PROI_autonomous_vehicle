#include "map.h"
#include "Position.h"

Field::Field(Position location) noexcept {
    this->location = location;
}
Position Field::getLocation() const noexcept {
    return this->location;
}
bool Field::getIsBarrier() const noexcept {
    return isBarrier;
}
void Field::setIsBarrier(bool barrier) {
    this->isBarrier = barrier;
}
int Field::getHumidity() const noexcept {
    return humidity;
}
void Field::setHumidity(int hum) {
    this->humidity = hum;
}
int Field::getSurface_Condition() const noexcept {
    return surface_condition;
}
void Field::setSurface_Condition(int condition) {
    this->surface_condition = condition;
}

Map::Map() noexcept {
    for (int i = 0; i < 100; i++)
    {
        std::vector<Field> inside;
        for (int j = 0; j < 100; j++)
        {
            Field field(Position(i, j));
            inside.push_back(field);
        }
        field_container.push_back(inside);
    }
}
void Map::setField(Field square) {
    Position v = square.getLocation();
    field_container[v.x][v.y] = square;
}
std::vector<std::vector<Field>> Map::getFieldContainer() const noexcept {
    return field_container;
}
Field Map::operator()(Position location) const noexcept {
    return field_container[location.x][location.y];
}
