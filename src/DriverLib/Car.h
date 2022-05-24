#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Car
{
private:
    vector<int> position;
    vector<int> destination;
    vector<int> attributes;
    char direction = 's';
public:
    vector<int> getAttributes() const noexcept;
    void turnLeft() noexcept {}
    void turnRight() noexcept {}
    void accelerate() noexcept {}
    char getDirection() const noexcept {
        return this->direction;
    }
};
