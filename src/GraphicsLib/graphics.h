#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <memory>
#include "../MapLib/map.h"

class Coords{
public:
    int X,Y;
    Coords(): X(0), Y(0){};
    Coords(int X, int Y): X(X), Y(Y) {};
    void x_up();
    void y_up();
    COORD getCOORD();
};

// Loader used to load and modify data
class Loader{
private:
    std::string tmp;
};

//Different Displays Options
class Display{
public:
    Display() = default;
    virtual void drawPoint(Coords coords, char character) = 0;
};

class ConsoleDisplay: public Display{
public:
    ConsoleDisplay() = default;
    void setPosition(Coords coords);
    void drawPoint(Coords coords, char character) override;
};


// Objects / Geometrics
class Object{
protected:
    Coords coords = Coords(0,0);
    Display& display;
public:
    Object(Coords coords, Display& display): coords(coords), display(display) {};
    virtual void draw() = 0;
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

//Container class / event loop
class Drawing{
    std::vector<std::unique_ptr<Object>> objects;
    std::vector<std::reference_wrapper<Object>> objectsReferences;
public:
    Drawing() = default;

    Drawing& operator+=(std::unique_ptr<Object> object){
        objects.push_back(std::move(object));
        objectsReferences = getObjects();
        return *this;
    }

    std::vector<std::reference_wrapper<Object>> getObjects(){
        std::vector<std::reference_wrapper<Object>> References;
        for (auto& pointer: objects){
            References.push_back(std::ref(*pointer));
        }
        return References;
    }

    std::reference_wrapper<Object> operator[](int index) const noexcept{
        return objectsReferences[index];
    }

    void display(){
        for(auto object: objectsReferences){
            object.get().draw();
        }
    }

};
