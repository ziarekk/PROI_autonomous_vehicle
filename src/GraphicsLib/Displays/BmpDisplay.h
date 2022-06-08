#pragma once
#include "displays.h"
#include "../EasyBMPLib/EasyBMP.h"

/*
Autor: Karol Ziarek
*/

// colors
const EasyBMP::RGBColor black(0, 0, 0);
const EasyBMP::RGBColor white(255, 255, 255);
const EasyBMP::RGBColor red(255, 0, 0);

class BmpDisplay: public Display{
private:
    std::string output = "sprite.bmp";
    int spritesCounter = 1;
    unsigned width;
    unsigned height;
    EasyBMP::Image img = EasyBMP::Image(width, height, "sprite.bmp",  white);

public:
    BmpDisplay(unsigned width, unsigned height): width(width), height(height){
        img.SetFileName(output);
    };
    void  generateImage();
    void  drawPoint(Position position, char character) override;
    void  nextImageName();
    char getTexture(Field& field) override;
    EasyBMP::RGBColor getColor(char character);
};

