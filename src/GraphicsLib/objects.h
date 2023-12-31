#pragma once
#include "Displays/displays.h"
#include "Displays/BmpDisplay.h"
/*
Autor: Karol Ziarek
*/

class Object{
protected:
    Position position;
    Display& display;
public:
    Object(Position position, Display& display): position(position), display(display) {};
    virtual void draw() = 0;
};

class DisplayTile: public Object{
protected:
    char character=char(2);
public:
    DisplayTile(Position position, Display& display, char character): Object(position, display){
        this->character = character;
    };
    void draw() override;
};

class DisplayCar: public Object{
protected:
    char character=char(2);
public:
    DisplayCar(Position position, Display& display): Object(position, display){};
    void draw() override;
};

class DisplayLine: public Object{
protected:
    int length = 0;
    bool axis = false;
    char character='0';
public:
    DisplayLine(Position position, int length, bool axis, char character, Display& display):
            Object(position, display), length(length), axis(axis), character(character) {};
    void draw() override;
};

class clearConsole: public Object{
protected:
    int length;
    int height;
    char character;
public:
    clearConsole(int length, int height,  char character, Display& display):
    Object(Position(0,0), display), length(length), height(height), character(character) {};

    void draw() override;

};

class printBMP: public Object{
protected:
    BmpDisplay& bmpDisplay;
public:
    printBMP(BmpDisplay& bmpDisplay):
        Object(Position(0,0), bmpDisplay), bmpDisplay(bmpDisplay){};

    void draw() override{
        bmpDisplay.generateImage();
    };
};