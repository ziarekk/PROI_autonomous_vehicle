#include "map.h"
#include "Position.h"
#include <string>
#include <fstream>
#include <iostream>
#include <utility>

/*
Autor: Szymon Jankowski
*/

Map::Map(int width, int height) {
    for (int i = 0; i < width; i++)
    {
        std::vector<Field> inside;
        for (int j = 0; j < height; j++)
        {
            Field field(Position(j, i), false, 60, 10, 20);
            inside.push_back(field);
        }
        field_container.push_back(inside);
    }
}

Map::Map(std::string fileName) {
    this->read_from_file(fileName);
}

void Map::setField(Field square) {
    field_container[square.location.y][square.location.x] = square;
}

void Map::setFieldContainer(std::vector<std::vector<Field>> new_map) {
    field_container = std::move(new_map);
}

std::vector<std::vector<Field>> Map::getFieldContainer() const noexcept {
    return field_container;
}

Field Map::operator()(Position location) const noexcept {
    return field_container[location.y][location.x];
}

void Map::read_from_file(std::string fileName)
{
    std::string line;
    std::ifstream myFile;
    myFile.open(fileName, std::ios::in);
    if (myFile.is_open())
    {
        int i=0;
        while (getline(myFile, line))
        {
            int pos1=0;
            int pos2=0;
            std::string field_info;
            std::string delimiter1 = "(";
            std::string delimiter2 = ")";
            int j=0;
            std::vector<Field> inside;
            while ((pos2 = line.find(delimiter2))>0)
            {
                pos1 = line.find(delimiter1);
                field_info = line.substr(pos1+1, pos2-1);
                line.erase(pos1, pos2+1);
                std::string delimiter = ", ";
                std::string isBar;
                bool isBarBool;
                int hum, surface, temp;
                isBar = field_info.substr(0, field_info.find(delimiter));
                if (isBar == "true")
                    isBarBool = true;
                else
                    isBarBool = false;
                field_info.erase(0, field_info.find(delimiter)+2);
                hum = stoi(field_info.substr(0, field_info.find(delimiter)));
                field_info.erase(0, field_info.find(delimiter)+2);
                surface = stoi(field_info.substr(0, field_info.find(delimiter)));
                field_info.erase(0, field_info.find(delimiter)+2);
                temp = stoi(field_info.substr(0, field_info.find(delimiter)));
                Position pos(j, i);
                Field field(pos, isBarBool, hum, surface, temp);
                inside.push_back(field);
                j++;
            }
            field_container.push_back(inside);
            i++;
        }

        myFile.close();
    }
}