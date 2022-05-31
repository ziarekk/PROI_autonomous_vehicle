#include "CarLib/Car.h"
#include "DriverLib/BaseDriver/Driver.h"
#include "GraphicsLib/data_loader.h"
#include "GraphicsLib/Displays/ConsoleDisplay.h"
#include "DriverLib/StupidDriver/StupidDriver.h"

int main() {

   // Map map(20,20);
    Map map("map_1.txt");
    Drawing drawUI;
    ConsoleDisplay cmdDisplay;
    Car car(Position(11, 11), map);
    dataLoader Loader(drawUI, cmdDisplay, map, car);


/*
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

    //add obstacle
    map.setField(Field(Position(5,6), true, 0, 0, 0));
    map.setField(Field(Position(6,6), true, 0, 0, 0));
    map.setField(Field(Position(7,9), true, 0, 0, 0));
    map.setField(Field(Position(8,8), true, 0, 0, 0));
    map.setField(Field(Position(10,5), true, 0, 0, 0));
    map.setField(Field(Position(10,10), true, 0, 0, 0));
    map.setField(Field(Position(5,8), true, 0, 0, 0));
    map.setField(Field(Position(5,10), true, 0, 0, 0));
    map.setField(Field(Position(6,11), true, 0, 0, 0));

*/
    //load data from map&car and display it
    Loader.load_data();
    drawUI.display();

    // main loop
     Driver driver(car, Position(5, 5));
    // StupidDriver driver(car);
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
