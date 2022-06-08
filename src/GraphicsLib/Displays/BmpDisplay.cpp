#include "BmpDisplay.h"

/*
Autor: Karol Ziarek
*/

void BmpDisplay::drawPoint(Position position, char character) {
    img.SetPixel(position.x, position.y, getColor(character), true);
}

void BmpDisplay::generateImage(){
    nextImageName();
    img.Write();
}

void BmpDisplay::nextImageName(){
    output = "sprite";
    output += std::to_string(spritesCounter);
    output += ".bmp";
    img.SetFileName(output);
    spritesCounter ++;

}

EasyBMP::RGBColor BmpDisplay::getColor(char character) {
    if (character == char(2)){
         return red;}
    else if (character == ' '){
        return white;}
    else{
        return black;}
}

char BmpDisplay::getTexture(Field &field) {
    if(field.isBarrier)
        return 'X';
    else
        return  ' ';
}
