#include "Menu_functions.h"
#include "Displays/BmpDisplay.h"
#include "BaseDriver/Driver.h"
#include "StupidDriver/StupidDriver.h"

/*
Autor: Karol Ziarek
*/

int main() {
    Drawing drawUI;

    int mapNumber = takeMap();
    char driverType= takeDriver();
    std::string mapName = chooseMap(mapNumber);

    Map map(mapName);

    Position startingPoint = takeStartingPoint(map);
    Position destinationPoint = takeDestinationPoint(map);

    BmpDisplay display(map.getFieldContainer()[0].size(), map.getFieldContainer().size());

    Car car(startingPoint, map);
    dataLoader Loader(drawUI, display, map, car);

    //drawUI += std::make_unique<clearConsole>(clearConsole(70, 70, ' ', display));
   // drawUI.display();

    Loader.load_data();
    drawUI += std::make_unique<printBMP>(printBMP(display));
    drawUI.display();

    std::string str;

    Position footer(0, int(map.getFieldContainer().size()));

    if(driverType == 'S')
        {
        StupidDriver driver(car);
        while (!(car.getLocation() == destinationPoint)) {
            Loader.load_data();
           // drawUI += std::make_unique<DisplayTile>(DisplayTile(footer, display, ' '));
            drawUI += std::make_unique<printBMP>(printBMP(display));
            drawUI.display();

            //displayCurrentState(car, destinationPoint);

            driver.navigate(car);
            car.move();
            driver.updatePosition(car);

          //  Sleep(100);
            }
        Loader.load_data();
        drawUI += std::make_unique<printBMP>(printBMP(display));
        //drawUI += std::make_unique<DisplayTile>(DisplayTile(footer, display, ' '));
        drawUI.display();
        //displayCurrentState(car, destinationPoint);
        }

    else {
        Driver driver(car, destinationPoint);
        while (!(car.getLocation() == destinationPoint)) {
            Loader.load_data();
            //drawUI += std::make_unique<DisplayTile>(DisplayTile(footer, display, ' '));
            drawUI += std::make_unique<printBMP>(printBMP(display));
            drawUI.display();

            //displayCurrentState(car, destinationPoint);

            driver.navigate(car);
            car.move();
            driver.updatePosition(car);

          //  Sleep(100);
        }
        Loader.load_data();
       // drawUI += std::make_unique<DisplayTile>(DisplayTile(footer, display, ' '));
        drawUI += std::make_unique<printBMP>(printBMP(display));
        drawUI.display();
        //displayCurrentState(car, destinationPoint);
    }

    system("pause");
    return 0;
}
