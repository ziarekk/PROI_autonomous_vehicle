#include "CarLib/Car.h"
#include "DriverLib/BaseDriver/Driver.h"
#include "GraphicsLib/data_loader.h"
#include "GraphicsLib/Displays/ConsoleDisplay.h"
#include "DriverLib/StupidDriver/StupidDriver.h"

int takeMap(ConsoleDisplay& display, Drawing& drawing) {
    int mapNumber = 0;
    while (mapNumber > 3 || mapNumber < 1) {
        std::cout << "There are 3 available maps: map_1, map_2, map_3" << std::endl;
        std::cout << "Type number of the map: ";
        std::cin >> mapNumber;
    }
    return mapNumber;
}

char takeDriver(ConsoleDisplay& display, Drawing& drawing) {
    char driverType = 'X';
    while(driverType!='S' && driverType!='I'){
        std::cout<<"There are 2 available drivers: S - stupid, I - Intelligent"<<std::endl;
        std::cout<<"Type the letter of the driver: ";
        std::cin>>driverType;
    }
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

Position takeStartingPoint(ConsoleDisplay& display, Drawing& drawing, Map& map) {
    Position startingPoint;
    do {
        std::cout << "Now choose starting point!" << std::endl << "X = ";
        std::cin >> startingPoint.x;
        std::cout << "Y = ";
        std::cin >> startingPoint.y;
    } while (map(startingPoint).isBarrier);
    return startingPoint;
}

Position takeDestinationPoint(ConsoleDisplay& display, Drawing& drawing, Map& map){
    Position destinationPoint;
    do{
        std::cout<<"Now choose destination point!"<<std::endl<<"X = ";
        std::cin>>destinationPoint.x;
        std::cout<<"Y = ";
        std::cin>>destinationPoint.y;
    }while(map(destinationPoint).isBarrier);
    return destinationPoint;
}

int main() {
    Drawing drawUI;
    ConsoleDisplay cmdDisplay;

    int mapNumber = takeMap(cmdDisplay, drawUI);
    char driverType= takeDriver(cmdDisplay, drawUI);
    std::string mapName = chooseMap(mapNumber);

    Map map(mapName);

    Position startingPoint = takeStartingPoint(cmdDisplay, drawUI, map);
    Position destinationPoint = takeDestinationPoint(cmdDisplay, drawUI, map);


    Car car(startingPoint, map);
    dataLoader Loader(drawUI, cmdDisplay, map, car);

    drawUI += std::make_unique<clearConsole>(clearConsole(70, 70, ' ', cmdDisplay));
    drawUI.display();
    //load data from map&car and display it
    Loader.load_data();
    drawUI.display();

    std::string str;

    Position footer(0, map.getFieldContainer().size());
    Position footer2(0, map.getFieldContainer().size()+12);

    if(driverType == 'S')
        {
        StupidDriver driver(car);
        while (!(car.getLocation() == destinationPoint)) {
            Loader.load_data();
            drawUI += std::make_unique<DisplayTile>(DisplayTile(footer, cmdDisplay, ' '));
            drawUI.display();

            std::cout<<std::endl<<"Current Position: ("<<car.getLocation().x<<","<< car.getLocation().y<<")   ";
            std::cout<<std::endl<<"Destination: ("<<destinationPoint.x<<","<< destinationPoint.y<<")   ";
            std::cout<<std::endl;
            std::cout<<std::endl<<"Road quality: "<<car.getSurfaceCondition();
            std::cout<<std::endl<<"Road temperature: "<<car.getTemperature();
            std::cout<<std::endl<<"Road humidity: "<<car.getHumidityInfo();
            std::cout<<std::endl;
            std::cout<<std::endl<<"Wall distances: "<<std::endl;
            std::cout<<"Front - "<<car.getRadarInfo()[0]<<";  Left - "<<car.getRadarInfo()[1];
            std::cout<<";  Right - "<<car.getRadarInfo()[2]<<std::endl;


            driver.navigate(car);
            car.move();
            driver.updatePosition(car);

            Sleep(1000);
            }
        Loader.load_data();
        drawUI += std::make_unique<DisplayTile>(DisplayTile(footer2, cmdDisplay, ' '));
        drawUI.display();
        std::cout<<std::endl;
        }

    else {
        Driver driver(car, destinationPoint);
        while (!(car.getLocation() == destinationPoint)) {
            Loader.load_data();
            drawUI += std::make_unique<DisplayTile>(DisplayTile(footer, cmdDisplay, ' '));
            drawUI.display();
            std::cout<<std::endl<<"Current Position: ("<<car.getLocation().x<<","<< car.getLocation().y<<")    ";
            std::cout<<std::endl<<"Destination: ("<<destinationPoint.x<<","<< destinationPoint.y<<")   ";
            std::cout<<std::endl;
            std::cout<<std::endl<<"Road quality: "<<car.getSurfaceCondition()<<"          ";
            std::cout<<std::endl<<"Road temperature: "<<car.getTemperature()<<"          ";
            std::cout<<std::endl<<"Road humidity: "<<car.getHumidityInfo()<<"          ";
            std::cout<<std::endl;
            std::cout<<std::endl<<"Wall distances: "<<std::endl;
            std::cout<<"Front - "<<car.getRadarInfo()[0]<<";  Left - "<<car.getRadarInfo()[1];
            std::cout<<";  Right - "<<car.getRadarInfo()[2]<<"          "<<std::endl;


            driver.navigate(car);
            car.move();
            driver.updatePosition(car);

            Sleep(1000);
        }
        Loader.load_data();
        drawUI += std::make_unique<DisplayTile>(DisplayTile(footer2, cmdDisplay, ' '));
        drawUI.display();
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}
