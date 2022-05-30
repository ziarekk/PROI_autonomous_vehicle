#include "Sensor.h"

bool TouchSensor::getIsTouched(Position location, Map& map)  {
    int x = location.x;
    int y = location.y;
    Position loc1(x-1, y);
    if (map(loc1).isBarrier)
        return isTouched = true;
    Position loc2(x+1, y);
    if (map(loc2).isBarrier)
        return isTouched = true;
    Position loc3(x, y-1);
    if (map(loc3).isBarrier)
        return isTouched = true;
    Position loc4(x, y+1);
    if (map(loc4).isBarrier)
        return isTouched = true;
    isTouched = false;
    return isTouched;
}

int HumiditySensor::getInfo(Position location, Map& map)  {
    return map(location).humidity;
}

int TemperatureSensor::getInfo(Position location, Map& map)  {
    return map(location).temperature;
}

int SurfaceSensor::getInfo(Position location, Map& map) {
    return  map(location).surface_condition;
}

std::vector<int> RadarSensor::getInfo(Position location, Map& map, char direction) {
    Position loc(location.x, location.y);
    int left, right, up, down;
    left = right = up = down = 0;
    do {
        left += 1;
        loc.x -= 1;
    }
    while (!map(loc).isBarrier);

    loc.x = location.x;
    do {
        right += 1;
        loc.x += 1;
    }
    while (!map(loc).isBarrier);

    loc.x = location.x;
    do {
        up += 1;
        loc.y -= 1;
    }
    while (!map(loc).isBarrier);

    loc.y = location.y;
    do {
        down += 1;
        loc.y += 1;
    }
    while (!map(loc).isBarrier);

    std::vector<int> distances;
    if (direction == 'n') {
        distances.push_back(up);
        distances.push_back(left);
        distances.push_back(right);
    }
    else if (direction == 's') {
        distances.push_back(down);
        distances.push_back(right);
        distances.push_back(left);
    }
    else if (direction == 'e') {
        distances.push_back(right);
        distances.push_back(up);
        distances.push_back(down);
    }
    else {
        distances.push_back(left);
        distances.push_back(down);
        distances.push_back(up);
    }
    return distances;
}
