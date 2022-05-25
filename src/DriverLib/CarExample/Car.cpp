#include <iostream>
#include <vector>
#include "Car.h"
#include "../BaseDriver/Driver.h"

using namespace std;

Car::Car(char direction) noexcept {
    this->direction = direction;
}

Car::Car(vector<int> position, vector<int> destination, vector<int> attributes) noexcept {
    this->position = position;
    this->destination = destination;
    this->attributes = attributes;
}

vector<int> Car::getAttributes() const noexcept {
    return this->attributes;
}

char Car::getDirection() const noexcept {
    return this->direction;
}

void Car::turnLeft() noexcept {
    if (this->direction == 'n') {
        this->direction = 'w';
    }
    else if (this->direction == 's') {
        this->direction = 'e';
    }
    else if (this->direction == 'w') {
        this->direction = 's';
    }
    else {
        this->direction = 'n';
    }
}

void Car::turnRight() noexcept {
    if (this->direction == 'n') {
        this->direction = 'e';
    }
    else if (this->direction == 's') {
        this->direction = 'w';
    }
    else if (this->direction == 'w') {
        this->direction = 'n';
    }
    else {
        this->direction = 's';
    }
}

void Car::accelerate() noexcept {

}
