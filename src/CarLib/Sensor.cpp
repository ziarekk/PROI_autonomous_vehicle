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
    int x = location.x;
    int y = location.y;
    int front=0, left=0, right=0;

    if (direction == 'n')
    {
        for (int i = y; i < map.getFieldContainer().size(); i++)
        {
            Position loc1(x, i);
            if (map(loc1).isBarrier)
            {
                front = i - y;
                break;
            }
        }
        if (front==0)
            front = map.getFieldContainer().size() - y;
        for (int i = x; i > 0; i--)
        {
            Position loc3(i, y);
            if (map(loc3).isBarrier)
            {
                left = x - i;
                break;
            }
        }
        if (left==0)
            left = x - 0;
        for (int i=x;i<map.getFieldContainer().size();i++)
        {
            Position loc2(i, y);
            if (map(loc2).isBarrier)
            {
                right = i - x;
                break;
            }
        }
        if (right==0)
            right = map.getFieldContainer().size() - x;
    }

    if (direction == 'e')
    {
        for (int i=x;i<map.getFieldContainer().size();i++)
        {
            Position loc2(i, y);
            if (map(loc2).isBarrier)
            {
                front = i - x;
                break;
            }
        }
        if (front==0)
            front = map.getFieldContainer().size() - x;
        for (int i = y; i < map.getFieldContainer().size(); i++)
        {
            Position loc1(x, i);
            if (map(loc1).isBarrier)
            {
                left = i - y;
                break;
            }
        }
        if (left==0)
            left = map.getFieldContainer().size() - y;
    }

    if (direction == 'w')
    {
        for (int i = x; i > 0; i--) {
            Position loc3(i, y);
            if (map(loc3).isBarrier) {
                front = x - i;
                break;
            }
        }
        if (front==0)
            front = x - 0;
        for (int i=y;y>0;i--)
        {
            Position loc4(x, i);
            if (map(loc4).isBarrier)
            {
                left = y - i;
                break;
            }
        }
        if (left==0)
            left = y;
        for (int i = y; i < map.getFieldContainer().size(); i++)
        {
            Position loc1(x, i);
            if (map(loc1).isBarrier)
            {
                right = i - y;
                break;
            }
        }
        if (right==0)
            right = map.getFieldContainer().size() - y;
    }

    if (direction == 's')
    {
        for (int i=y;y>0;i--)
        {
            Position loc4(x, i);
            if (map(loc4).isBarrier)
            {
                front = y - i;
                break;
            }
        }
        if (front==0)
            front = y - 0;
        for (int i=x;i<map.getFieldContainer().size();i++)
        {
            Position loc2(i, y);
            if (map(loc2).isBarrier)
            {
                left = i - x;
                break;
            }
        }
        if (left==0)
            left = map.getFieldContainer().size() - x;
        for (int i = x; i > 0; i--)
        {
            Position loc3(i, y);
            if (map(loc3).isBarrier)
            {
                right = x - i;
                break;
            }
        }
        if (right==0)
            right = x - 0;

    }

    std::vector<int> distances;
    distances.push_back(front);
    distances.push_back(left);
    distances.push_back(right);
    return distances;
}

