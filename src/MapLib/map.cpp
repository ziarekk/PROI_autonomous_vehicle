#include "map.h"

Field::Field(int* location) noexcept {
    this->xLocation = location[0];
    this->yLocation = location[1];
}
int* Field::getLocation() const noexcept {
    int *loc = new int[2];
    loc[0] = xLocation;
    loc[1] = yLocation;
    return loc;
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
World::World() noexcept {
    std::vector<std::vector<Field>> outside;
    for (int i = 0; i < 100; i++)
    {
        std::vector<Field> inside;
        for (int j = 0; j < 100; j++)
        {
            int loc[2];
            loc[0] = i;
            loc[1] = j;
            Field field(loc);
            inside.push_back(field);
        }
        outside.push_back(inside);
    }
    field_container = outside;
}
void World::setField(Field square) {
    int* v = square.getLocation();
    field_container[v[0]][v[1]] = square;
}
std::vector<std::vector<Field>> World::getFieldContainer() const noexcept {
    return field_container;
}
Field World::operator()(int* location) const noexcept {
    return field_container[location[0]][location[1]];
}