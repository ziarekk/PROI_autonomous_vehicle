#include <gtest/gtest.h>
#include "StupidDriver.h"
#include "../CarLib/Car.h"
#include "../MapLib/Position.h"
#include "../MapLib/map.h"

using namespace std;

namespace
{
void createMap(Map &map) {
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
}

TEST(StupidDriver, Constructor)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(5, 5), map);
    StupidDriver dv(car);

    ASSERT_EQ(dv.getSpeed(), 20);
    ASSERT_EQ(dv.getTemperature(), 20);
    ASSERT_EQ(dv.getHumidity(), 60);
    ASSERT_EQ(dv.getRoadQuality(), 10);
}

TEST(StupidDriver, changeDirection_left_v1)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(1, 1), map);
    StupidDriver dv(car);

    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 'e');
}

TEST(StupidDriver, changeDirection_left_v2)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(18, 18), map, 'e');
    StupidDriver dv(car);

    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 'n');
}

TEST(StupidDriver, changeDirection_right_v1)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(1, 18), map, 'w');
    StupidDriver dv(car);

    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 'n');
}

// TEST(StupidDriver, changeDirection_right_v2)
// {
//     Map map(20,20);
//     createMap(map);
//     Car car(Position(18, 1), map, 'e');
//     StupidDriver dv(car);

//     dv.navigate(car);
//     dv.updatePosition(car);
//     ASSERT_EQ(car.getDirection(), 's');
// }
}
