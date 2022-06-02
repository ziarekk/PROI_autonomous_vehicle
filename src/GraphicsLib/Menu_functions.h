#pragma once
#include <iostream>
#include "../CarLib/Car.h"
#include "data_loader.h"

/*
Autor: Karol Ziarek
*/

int takeMap() {
    int mapNumber = 0;
    while (mapNumber > 3 || mapNumber < 1) {
        std::cout << "There are 3 available maps: map_1, map_2, map_3" << std::endl;
        std::cout << "Type number of the map: ";
        std::cin >> mapNumber;
    }
    return mapNumber;
}

char takeDriver() {
    char driverType = 'X';
    while(driverType!='S' && driverType!='I'){
        std::cout<<"There are 2 available drivers: S - stupid, I - Intelligent"<<std::endl;
        std::cout<<"Type the letter of the driver: ";
        std::cin>>driverType;
    }
    return driverType;
}

std::string chooseMap(int mType)
{
    if(mType== 1)
        return "map_1.txt";
    else if(mType == 2)
        return "map_2.txt";
    else
        return "map_3.txt";
}

Position takeStartingPoint(Map& map) {
    Position startingPoint;
    do {
        std::cout << "Now choose starting point!" << std::endl << "X = ";
        std::cin >> startingPoint.x;
        std::cout << "Y = ";
        std::cin >> startingPoint.y;
    } while (map(startingPoint).isBarrier);
    return startingPoint;
}

Position takeDestinationPoint(Map& map){
    Position destinationPoint;
    do{
        std::cout<<"Now choose destination point!"<<std::endl<<"X = ";
        std::cin>>destinationPoint.x;
        std::cout<<"Y = ";
        std::cin>>destinationPoint.y;
    }while(map(destinationPoint).isBarrier);
    return destinationPoint;
}

void displayCurrentState(Car& car, Position destinationPoint){
    std::cout<<std::endl<<"Current Position: ("<<car.getLocation().x<<","<< car.getLocation().y<<")   ";
    std::cout<<std::endl<<"Destination: ("<<destinationPoint.x<<","<< destinationPoint.y<<")   ";
    std::cout<<std::endl;
    std::cout<<std::endl<<"Road quality: "<<car.getSurfaceCondition()<<"   ";
    std::cout<<std::endl<<"Road temperature: "<<car.getTemperature()<<"   ";
    std::cout<<std::endl<<"Road humidity: "<<car.getHumidityInfo()<<"   ";
    std::cout<<std::endl;
    std::cout<<std::endl<<"Wall distances: "<<std::endl;
    std::cout<<"Front - "<<car.getRadarInfo()[0]<<";  Left - "<<car.getRadarInfo()[1];
    std::cout<<";  Right - "<<car.getRadarInfo()[2]<<"     "<<std::endl;

}