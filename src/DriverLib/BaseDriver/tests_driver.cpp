#include <gtest/gtest.h>
#include "Driver.h"

using namespace std;

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
            Field tmpField1(position2, true, 0, 0, 0);
            map.setField(tmpField1);

            Position position3(19,i);
            Field tmpField2(position3, true, 0, 0, 0);
            map.setField(tmpField2);
        }
    }
}

TEST(Driver, Constructor)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(5, 5), map);
    Driver dv(car, Position(8, 8));

    ASSERT_EQ(dv.getDestination(), Position(8, 8));
    ASSERT_EQ(dv.getSpeed(), 20);
    ASSERT_EQ(dv.getTemperature(), 20);
    ASSERT_EQ(dv.getHumidity(), 60);
    ASSERT_EQ(dv.getRoadQuality(), 10);
}

TEST(Driver, updatePos)
{
    Map map(20,20);
    createMap(map);
    map.setField(Field(Position(5,6), true, 10, 20, 50));
    Car car(Position(5, 5), map);
    Driver dv(car, Position(8, 8));

    car.setDirection('e');
    car.setLocation(Position(9, 8));
    dv.updatePosition(car);
    ASSERT_EQ(dv.getDirection(), car.getDirection());
}

TEST(Driver, navigate_end)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(5, 5), map);
    Driver dv(car, Position(5, 5));

    dv.navigate(car);
    ASSERT_EQ(dv.getSpeed(), 0);
}

TEST(Driver, navigate_turnLeft_v1)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(5, 5), map);
    Driver dv(car, Position(4, 5));

    ASSERT_NE(car.getDirection(), 'w');
    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 'w');
}

TEST(Driver, navigate_turnLeft_v2)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(5, 5), map, 's');
    Driver dv(car, Position(7, 5));

    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 'e');
}

TEST(Driver, navigate_turnRight_v1)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(5, 5), map, 's');
    Driver dv(car, Position(3, 6));

    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 'w');
}

TEST(Driver, navigate_turnRight_v2)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(5, 5), map, 'n');
    Driver dv(car, Position(8, 8));

    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 'e');
}

TEST(Driver, navigate_noChange_v1)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(5, 5), map, 'e');
    Driver dv(car, Position(8, 5));

    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 'e');
}

TEST(Driver, navigate_noChange_v2)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(5, 5), map, 'n');
    Driver dv(car, Position(5, 3));

    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 'n');
}

TEST(Driver, navigate_avoidWall_go_left)
{
    Map map(20,20);
    createMap(map);
    map.setField(Field(Position(5,4), true, 10, 20, 50));
    Car car(Position(5, 5), map, 'n');
    Driver dv(car, Position(5, 2));

    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 'e');
}

TEST(Driver, navigate_avoidWall_go_right)
{
    Map map(20,20);
    createMap(map);
    map.setField(Field(Position(6,5), true, 10, 20, 50));
    Car car(Position(5, 5), map, 'e');
    Driver dv(car, Position(7, 8));

    dv.navigate(car);
    dv.updatePosition(car);
    ASSERT_EQ(car.getDirection(), 's');
}
