#pragma once
#include "displays.h"

class Object{
protected:
    Coords coords = Coords(0,0);
    Display& display;
public:
    Object(Coords coords, Display& display): coords(coords), display(display) {};
    virtual void draw() = 0;
};

class DisplayTile: public Object{
protected:
    char character=char(2);
public:
    DisplayTile(Coords coords, Display& display, char character): Object(coords, display){
        this->character = character;
    };
    void draw() override;
};

class DisplayCar: public Object{
protected:
    char character=char(2);
public:
    DisplayCar(Coords coords, Display& display): Object(coords, display){};
    void draw() override;
};

class DisplayLine: public Object{
protected:
    int length = 0;
    bool axis = false;
    char character='0';
public:
    DisplayLine(Coords coords, int length, bool axis, char character, Display& display):
            Object(coords, display), length(length), axis(axis), character(character) {};
    void draw() override;
};