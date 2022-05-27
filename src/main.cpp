#include "Car.h"
#include "data_loader.h"

int main() {

    Map map;
    Drawing drawUI;
    ConsoleDisplay cmdDisplay;
    Position position(10,10);
    Car car(position, map);
    dataLoader Loader(drawUI, cmdDisplay, map, car);

    for(int i=0; i<20; i++) {
        if(i==0 || i==19)
            {
            for (int j = 0; j < 20; j++)
                {
                Position position2(j,i);
                Field tmpField(position2);
                tmpField.setIsBarrier(true);
                map.setField(tmpField);
                }
            }
        else
        {
            Position position2(0,i);
            Field tmpField1(position2);
            tmpField1.setIsBarrier(true);
            map.setField(tmpField1);

            Position position3(19,i);
            Field tmpField2(position3);
            tmpField2.setIsBarrier(true);
            map.setField(tmpField2);

        }

    }


    Loader.load_data();
    drawUI.display();

    Coords coord(25, 25);
    drawUI += std::make_unique<DisplayTile>(DisplayTile(coord, cmdDisplay, ' '));
    drawUI.display();
    system("pause");
    return 0;
}
