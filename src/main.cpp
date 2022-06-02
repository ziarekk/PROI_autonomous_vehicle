#include "GraphicsLib/Menu_functions.h"
#include "GraphicsLib/Displays/ConsoleDisplay.h"
#include "../DriverLib/BaseDriver/Driver.h"
#include "DriverLib/StupidDriver/StupidDriver.h"

/*
Autor: Karol Ziarek
*/

int main() {
    Drawing drawUI;
    ConsoleDisplay cmdDisplay;

    int mapNumber = takeMap();
    char driverType= takeDriver();
    std::string mapName = chooseMap(mapNumber);

    Map map(mapName);

    Position startingPoint = takeStartingPoint(map);
    Position destinationPoint = takeDestinationPoint(map);


    Car car(startingPoint, map);
    dataLoader Loader(drawUI, cmdDisplay, map, car);

    drawUI += std::make_unique<clearConsole>(clearConsole(70, 70, ' ', cmdDisplay));
    drawUI.display();

    Loader.load_data();
    drawUI.display();

    std::string str;

    Position footer(0, int(map.getFieldContainer().size()));

    if(driverType == 'S')
        {
        StupidDriver driver(car);
        while (!(car.getLocation() == destinationPoint)) {
            Loader.load_data();
            drawUI += std::make_unique<DisplayTile>(DisplayTile(footer, cmdDisplay, ' '));
            drawUI.display();

            displayCurrentState(car, destinationPoint);

            driver.navigate(car);
            car.move();
            driver.updatePosition(car);

            Sleep(1000);
            }
        Loader.load_data();
        drawUI += std::make_unique<DisplayTile>(DisplayTile(footer, cmdDisplay, ' '));
        drawUI.display();
        displayCurrentState(car, destinationPoint);
        }

    else {
        Driver driver(car, destinationPoint);
        while (!(car.getLocation() == destinationPoint)) {
            Loader.load_data();
            drawUI += std::make_unique<DisplayTile>(DisplayTile(footer, cmdDisplay, ' '));
            drawUI.display();

            displayCurrentState(car, destinationPoint);

            driver.navigate(car);
            car.move();
            driver.updatePosition(car);

            Sleep(1000);
        }
        Loader.load_data();
        drawUI += std::make_unique<DisplayTile>(DisplayTile(footer, cmdDisplay, ' '));
        drawUI.display();
        displayCurrentState(car, destinationPoint);
    }

    system("pause");
    return 0;
}
