#include <gtest/gtest.h>
#include "SafeDriver.h"
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

TEST(SafeDriver, Constructor)
{
    Map map(20,20);
    createMap(map);
    Car car(Position(5, 5), map);
    SafeDriver dv(car, Position(8, 8));

    ASSERT_EQ(dv.getDestination(), Position(8, 8));
    ASSERT_EQ(dv.getSpeed(), 20);
    ASSERT_EQ(dv.getTemperature(), 20);
    ASSERT_EQ(dv.getHumidity(), 60);
    ASSERT_EQ(dv.getRoadQuality(), 10);
}

TEST(SafeDriver, calculateSpeed_bad_road)
{
    Map map(20,20);
    createMap(map);
    map.setField(Field(Position(5, 5), true, 50, 4, 20));
    Car car(Position(5, 5), map);
    SafeDriver dv(car, Position(8, 8));

    ASSERT_EQ(dv.getDestination(), Position(8, 8));
    ASSERT_EQ(dv.getSpeed(), 10);
    ASSERT_EQ(dv.getTemperature(), 20);
}

TEST(SafeDriver, calculateSpeed_temp_0)
{
    Map map(20,20);
    createMap(map);
    map.setField(Field(Position(5, 5), true, 50, 10, 0));
    Car car(Position(5, 5), map);
    SafeDriver dv(car, Position(8, 8));

    ASSERT_EQ(dv.getSpeed(), 18);
}

TEST(SafeDriver, calculateSpeed_temp_minus)
{
    Map map(20,20);
    createMap(map);
    map.setField(Field(Position(5, 5), true, 50, 10, -5));
    Car car(Position(5, 5), map);
    SafeDriver dv(car, Position(8, 8));

    ASSERT_EQ(dv.getSpeed(), 14);
}

TEST(SafeDriver, calculateSpeed_high_hum)
{
    Map map(20,20);
    createMap(map);
    map.setField(Field(Position(5, 5), true, 82, 10, 15));
    Car car(Position(5, 5), map);
    SafeDriver dv(car, Position(8, 8));

    ASSERT_EQ(dv.getSpeed(), 16);
}

TEST(SafeDriver, calculateSpeed_very_high_hum)
{
    Map map(20,20);
    createMap(map);
    map.setField(Field(Position(5, 5), true, 95, 10, 15));
    Car car(Position(5, 5), map);
    SafeDriver dv(car, Position(8, 8));

    ASSERT_EQ(dv.getSpeed(), 12);
}

TEST(SafeDriver, calculateSpeed_difficult_conditions)
{
    Map map(20,20);
    createMap(map);
    map.setField(Field(Position(5, 5), true, 82, 3, 0));
    Car car(Position(5, 5), map);
    SafeDriver dv(car, Position(8, 8));

    ASSERT_EQ(dv.getSpeed(), 7);
}
}
