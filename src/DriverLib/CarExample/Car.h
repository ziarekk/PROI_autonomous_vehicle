#pragma once
#include <iostream>
#include <vector>

class Car
{
private:
    std::vector<int> position;
    std::vector<int> destination;
    std::vector<int> attributes;
    char direction;
public:
    Car(char direction) noexcept;
    Car(std::vector<int> position, std::vector<int> destination, std::vector<int> attributes) noexcept;
    std::vector<int> getAttributes() const noexcept;
    char getDirection() const noexcept;
    void turnLeft() noexcept;
    void turnRight() noexcept;
    void accelerate() noexcept;
};
