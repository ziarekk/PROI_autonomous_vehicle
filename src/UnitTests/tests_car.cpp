#include <gtest/gtest.h>
#include "Car.h"

/*
Autor: Szymon Jankowski
*/

namespace {
    TEST(CarUnitTest, getSpeedInfo1) {
        BaseCar car;
        ASSERT_EQ(0, car.getSpeed());
        car.accelerate(10);
        ASSERT_EQ(10, car.getSpeed());
        car.accelerate(30);
        ASSERT_EQ(20, car.getSpeed());
        ASSERT_EQ(20, car.getMaxSpeed());
    }

    TEST (CarUnitTest, getSpeedInfo2){
        BaseCar car;
        car.setMaxSpeed(10);
        ASSERT_EQ(10, car.getMaxSpeed());
        car.accelerate(20);
        ASSERT_EQ(10, car.getSpeed());
        car.accelerate(0);
        ASSERT_EQ(0, car.getSpeed());
    }
    TEST (CarUnitTest, turnLeft){
        BaseCar car;
        ASSERT_EQ('n', car.getDirection());
        car.turnLeft();
        ASSERT_EQ('w', car.getDirection());
        car.turnLeft();
        ASSERT_EQ('s', car.getDirection());
        car.turnLeft();
        ASSERT_EQ('e', car.getDirection());
        car.turnLeft();
        ASSERT_EQ('n', car.getDirection());
    }
    TEST (CarUnitTest, turnRight){
        BaseCar car;
        ASSERT_EQ('n', car.getDirection());
        car.turnRight();
        ASSERT_EQ('e', car.getDirection());
        car.turnRight();
        ASSERT_EQ('s', car.getDirection());
        car.turnRight();
        ASSERT_EQ('w', car.getDirection());
        car.turnRight();
        ASSERT_EQ('n', car.getDirection());
    }
    TEST (CarUnitTest, createBaseCar1){
        Position pos(4, 3);
        BaseCar car(pos);
        ASSERT_EQ(4, car.getLocation().x);
        ASSERT_EQ(3, car.getLocation().y);
        ASSERT_EQ('n', car.getDirection());
        ASSERT_EQ(20, car.getMaxSpeed());
    }
    TEST (CarUnitTest, createBaseCar2){
        Position pos(5, 6);
        BaseCar car(pos, 'e', 30);
        ASSERT_EQ(5, car.getLocation().x);
        ASSERT_EQ(6, car.getLocation().y);
        ASSERT_EQ('e', car.getDirection());
        ASSERT_EQ(30, car.getMaxSpeed());
    }
    TEST (CarUnitTest, setLocation1){
        Position pos1(5, 6);
        Position pos2(3, 1);
        BaseCar car(pos1, 'e', 30);
        ASSERT_EQ(5, car.getLocation().x);
        ASSERT_EQ(6, car.getLocation().y);
        car.setLocation(pos2);
        ASSERT_EQ(3, car.getLocation().x);
        ASSERT_EQ(1, car.getLocation().y);
    }
    TEST (CarUnitTest, setLocation2){
        Position pos(5, 6);
        BaseCar car;
        car.setLocation(pos);
        ASSERT_EQ(5, car.getLocation().x);
        ASSERT_EQ(6, car.getLocation().y);
    }
    TEST (CarUnitTest, moveCar){
        Position pos(5, 6);
        BaseCar car(pos, 'e', 20);
        ASSERT_EQ(5, car.getLocation().x);
        ASSERT_EQ(6, car.getLocation().y);
        ASSERT_EQ('e', car.getDirection());
        car.move();
        ASSERT_EQ(5, car.getLocation().x);
        ASSERT_EQ(6, car.getLocation().y);
        car.accelerate(10);
        ASSERT_EQ(10, car.getSpeed());
        car.move();
        ASSERT_EQ(6, car.getLocation().x);
        ASSERT_EQ(6, car.getLocation().y);
        car.turnLeft();
        ASSERT_EQ('n', car.getDirection());
        car.move();
        ASSERT_EQ(6, car.getLocation().x);
        ASSERT_EQ(5, car.getLocation().y);
        car.turnLeft();
        ASSERT_EQ('w', car.getDirection());
        car.move();
        ASSERT_EQ(5, car.getLocation().x);
        ASSERT_EQ(5, car.getLocation().y);
        car.turnLeft();
        ASSERT_EQ('s', car.getDirection());
        car.move();
        ASSERT_EQ(5, car.getLocation().x);
        ASSERT_EQ(6, car.getLocation().y);
    }
    TEST (CarUnitTest, createCar1) {
        Position pos(5, 6);
        Map map;
        Car car(pos, map);
        ASSERT_EQ(5, car.getLocation().x);
        ASSERT_EQ(6, car.getLocation().y);
        ASSERT_EQ(20, car.getMaxSpeed());
        ASSERT_EQ('n', car.getDirection());
        car.setDirection('s');
        ASSERT_EQ('s', car.getDirection());
    }
    TEST (CarUnitTest, createCar2) {
        Position pos(5, 6);
        Map map;
        Car car(pos, map, 'e', 40);
        ASSERT_EQ(5, car.getLocation().x);
        ASSERT_EQ(6, car.getLocation().y);
        ASSERT_EQ(40, car.getMaxSpeed());
        ASSERT_EQ('e', car.getDirection());
    }
    TEST (CarUnitTest, sensorsCar) {
        Position pos(5, 6);
        Position barrier_pos(6, 6);
        Map map(10, 10);
        Field field(pos, false, 30, 2, 20);
        Field barrier(barrier_pos, true, 20, 1, 30);
        map.setField(field);
        map.setField(barrier);
        Car car(pos, map, 'e', 30);
        ASSERT_EQ(true, car.getTouchInfo());
        ASSERT_EQ(30, car.getHumidityInfo());
        ASSERT_EQ(2, car.getSurfaceCondition());
        ASSERT_EQ(20, car.getTemperature());
    }
    TEST (CarUnitTest, radarCar) {
        Map map(10, 10);
        Position pos(5, 6);
        Position bar1(8, 6);
        Position bar2(5, 1);
        Position bar3(5, 7);
        Position bar4(3, 6);
        Field barrier1(bar1, true, 20, 1, 30);
        Field barrier2(bar2, true, 20, 1, 30);
        Field barrier3(bar3, true, 20, 1, 30);
        Field barrier4(bar4, true, 20, 1, 30);
        map.setField(barrier1);
        map.setField(barrier2);
        map.setField(barrier3);
        map.setField(barrier4);

        Car car(pos, map, 'e', 30);
        ASSERT_EQ(3, car.getRadarInfo()[0]);
        ASSERT_EQ(5, car.getRadarInfo()[1]);
        ASSERT_EQ(1, car.getRadarInfo()[2]);

        car.setDirection('n');
        ASSERT_EQ(5, car.getRadarInfo()[0]);
        ASSERT_EQ(2, car.getRadarInfo()[1]);
        ASSERT_EQ(3, car.getRadarInfo()[2]);

        car.setDirection('w');
        ASSERT_EQ(2, car.getRadarInfo()[0]);
        ASSERT_EQ(1, car.getRadarInfo()[1]);
        ASSERT_EQ(5, car.getRadarInfo()[2]);

        car.setDirection('s');
        ASSERT_EQ(1, car.getRadarInfo()[0]);
        ASSERT_EQ(3, car.getRadarInfo()[1]);
        ASSERT_EQ(2, car.getRadarInfo()[2]);
    }
    TEST (CarUnitTest, attributesCar) {
        Position pos(5, 6);
        Map map(10, 10);
        Field field(pos, false, 30, 2, 20);
        map.setField(field);
        Car car(pos, map, 'n', 30);
        ASSERT_EQ(2, car.getAttributes()[0]);
        ASSERT_EQ(20, car.getAttributes()[1]);
        ASSERT_EQ(30, car.getAttributes()[2]);
    }
}


