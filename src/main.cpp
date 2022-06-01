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

void clearConsole(ConsoleDisplay& display, Drawing& drawing){
    for(int i=0; i<60; i++){
        for(int j=0; j<60; j++){
            drawing += std::make_unique<DisplayTile>(DisplayTile(Position(i,j), display, ' '));
        }
    }
    drawing.display();
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

    clearConsole(cmdDisplay, drawUI);

    //load data from map&car and display it
    Loader.load_data();
    drawUI.display();

    std::string str;


    if(driverType == 'S')
        {
        StupidDriver driver(car);
        while (!(car.getLocation() == destinationPoint)) {
            Loader.load_data();
            drawUI += std::make_unique<DisplayTile>(DisplayTile(Position(1,25), cmdDisplay, ' '));
            drawUI.display();

            driver.navigate(car);
            car.move();
            driver.updatePosition(car);

            Sleep(500);
            }
        Loader.load_data();
        drawUI += std::make_unique<DisplayTile>(DisplayTile(Position(1,25), cmdDisplay, ' '));
        drawUI.display();
        }
    else {
        Driver driver(car, destinationPoint);
        while (!(car.getLocation() == destinationPoint)) {
            Loader.load_data();
            drawUI += std::make_unique<DisplayTile>(DisplayTile(Position(1,25), cmdDisplay, ' '));
            drawUI.display();

            driver.navigate(car);
            car.move();
            driver.updatePosition(car);

            Sleep(500);
        }
        Loader.load_data();
        drawUI += std::make_unique<DisplayTile>(DisplayTile(Position(1,25), cmdDisplay, ' '));
        drawUI.display();
    }

    system("pause");
    return 0;
}
