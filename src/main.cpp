#include "Car.h"
#include "data_loader.h"

int main() {

    Map map;
    Drawing drawUI;
    ConsoleDisplay cmdDisplay;
    Position position(8,8);
    Car car(position, map);
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


    // move the car and display it 8 times
    for(int i=8; i < 16; i++){
        Position newPos(i,i);
        car.setLocation(newPos);
        Loader.load_data();
        drawUI.display();

        // take a break so we can look
        drawUI += std::make_unique<DisplayTile>(DisplayTile(somePosition, cmdDisplay, ' '));
        drawUI.display();
        Sleep(1000);

    }

    // wait for the interaction
    system("pause");
    return 0;
}
