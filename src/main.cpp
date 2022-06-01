#include "CarLib/Car.h"
#include "DriverLib/BaseDriver/Driver.h"
#include "GraphicsLib/data_loader.h"
#include "GraphicsLib/Displays/ConsoleDisplay.h"
#include "DriverLib/StupidDriver/StupidDriver.h"

Drawing drawUI;
ConsoleDisplay cmdDisplay;
int mapNumber=0;
char driverType='X';
std::string mapName;
Position destinationPoint;
Position startingPoint;

void takeMapAndDriver(ConsoleDisplay& display, Drawing& drawing){
    while(mapNumber > 3 || mapNumber < 1){
        cmdDisplay.setPosition(display.ToCOORD(Position(0,0)));
        std::cout<<"There are 3 available maps: map_1, map_2, map_3"<<std::endl;
        std::cout<<"Type number of the map: ";
        std::cin>>mapNumber;
    }
    while(driverType!='S' || driverType!='I'){
        cmdDisplay.setPosition(display.ToCOORD(Position(2,0)));
        std::cout<<"There are 2 available drivers: S - stupid, I - Intelligent"<<std::endl;
        std::cout<<"Type the letter of the driver: ";
        std::cin>>driverType;
    }
}

void chooseMap(int mType)
    {
    if(mType== 1)
        mapName = "map_1.txt";
    else if(mType == 2)
        mapName = "map_2.txt";
    else
        mapName = "map_2.txt";
    }

void takePoint(Map& map){

}

int main() {



    Map map(mapName);
    Car car(startingPoint, map);
    dataLoader Loader(drawUI, cmdDisplay, map, car);


    // Initialize Driver
    if(driverType=='S'){
        StupidDriver driver(car);
    } else {
        Driver driver(car, destinationPoint);
    }


    //load data from map&car and display it
    Loader.load_data();
    drawUI.display();

    // main loop
     // Driver driver(car, Position(5, 5));
     StupidDriver driver(car);
    std::string str;
    char ch;
    while ((ch = std::cin.get()) != 's') {
        Loader.load_data();
        drawUI += std::make_unique<DisplayTile>(DisplayTile(Position(1,25), cmdDisplay, ' '));
        drawUI.display();

        driver.navigate(car);
        car.move();
        driver.updatePosition(car);

        str += ch;
    }

    system("pause");
    return 0;
}
