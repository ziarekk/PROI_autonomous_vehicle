#include "CarLib/Car.h"
#include "DriverLib/BaseDriver/Driver.h"
#include "data_loader.h"


int main() {

    Map map;
    Drawing drawUI;
    ConsoleDisplay cmdDisplay;
    Car car(Position(8, 8), map);
    dataLoader Loader(drawUI, cmdDisplay, map, car);


    // fulfill map
    for(int i=0; i<20; i++) {
        if(i==0 || i==19)
            {
            for (int j = 0; j < 20; j++)
                {
                Position position2(j,i);
                Field tmpField(position2, true, 0, 0, 0);
                map.setField(tmpField);
                }
            }
        else
        {
            Position position2(0,i);
            Field tmpField1(position2, true, 0, 0,0 );
            map.setField(tmpField1);

            Position position3(19,i);
            Field tmpField2(position3, true, 0, 0, 0);
            map.setField(tmpField2);

        }

    }

    // load data from map&car and display it
    Loader.load_data();
    drawUI.display();

    // take a break so we can look
    Position somePosition(25, 25);
    drawUI += std::make_unique<DisplayTile>(DisplayTile(somePosition, cmdDisplay, ' '));
    drawUI.display();
    Sleep(1000);


    //
    Driver driver(car, car.getDirection(), Position(5, 5));
    std::string str = "";
    char ch;
    while ((ch = std::cin.get()) != 27) {
        Loader.load_data();
        drawUI.display();

        std::cout << car.getDirection() << std::endl;
        driver.navigate(car);
        car.move();

        driver.updatePosition(car);

        drawUI += std::make_unique<DisplayTile>(DisplayTile(somePosition, cmdDisplay, ' '));
        drawUI.display();

        std::cout << car.getDirection() << std::endl;
        std::cout << std::endl;

        Sleep(1000);
        str += ch;
    }
    // for(int i=8; i < 16; i++){


    //     // take a break so we can look
    //     drawUI += std::make_unique<DisplayTile>(DisplayTile(somePosition, cmdDisplay, ' '));
    //     drawUI.display();
    //     Sleep(1000);

    // }

    // wait for the interaction
    system("pause");
    return 0;
}
