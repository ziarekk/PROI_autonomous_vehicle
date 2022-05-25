#include <algorithm>
#include <gtest/gtest.h>
#include "../CarLib/Car.h"

namespace {
    TEST(CarUnitTest, getSpeedTest1) {
        Car car;
        car.setSpeed(10);
        ASSERT_EQ(10, car.getSpeed());
    }
    TEST(CarUnitTest, getSpeedTest2) {
        Car car;
        car.setSpeed(15);
        ASSERT_EQ(15, car.getSpeed());
    }
    TEST(CarUnitTest, goLeftTest) {
        Car car;
        car.setSpeed(1);
        car.goLeft(5);
        ASSERT_EQ(44, car.getLocation().xLocation);
    }
    TEST(CarUnitTest, goLeftFasterTest) {
        Car car;
        car.setSpeed(2);
        car.goLeft(3);
        ASSERT_EQ(43, car.getLocation().xLocation);
    }
    TEST(CarUnitTest, goRightTest) {
        Car car;
        car.setSpeed(1);
        car.goRight(5);
        ASSERT_EQ(54, car.getLocation().xLocation);
    }
    TEST(CarUnitTest, goUpTest) {
        Car car;
        car.setSpeed(1);
        car.goUp(5);
        ASSERT_EQ(54, car.getLocation().yLocation);
    }
    TEST(CarUnitTest, goDownTest) {
        Car car;
        car.setSpeed(1);
        car.goDown(5);
        ASSERT_EQ(44, car.getLocation().yLocation);
    }
    TEST(CarUnitTest, BarrierEqualTest) {
        Location v; v.xLocation=49; v.yLocation=52;
        World world;
        Field bar(v);
        bar.setIsBarrier(true);
        world.setField(bar);
        Car car1;
        TouchSensor touch;
        car1.setSpeed(1);
        car1.goUp(3);
        ASSERT_EQ(v.xLocation, car1.getLocation().xLocation);
        ASSERT_EQ(v.yLocation, car1.getLocation().yLocation);
        ASSERT_EQ(true, touch.getInfo(v, world));
    }
    TEST(CarUnitTest, WorldConstructorTest) {
        World world;
        ASSERT_EQ(99, world.getFieldContainer()[99][99].getLocation().yLocation);
    }
    TEST(CarUnitTest, HumiditySensorTest) {
        Location v; v.xLocation=46; v.yLocation=49;
        World world;
        Field wet(v);
        wet.setHumidity(60);
        world.setField(wet);
        Car car1;
        HumiditySensor humidity;
        car1.setSpeed(1);
        car1.goLeft(3);
        ASSERT_EQ(v.xLocation, car1.getLocation().xLocation);
        ASSERT_EQ(v.yLocation, car1.getLocation().yLocation);
        ASSERT_EQ(60, humidity.getHumidity(v, world));
    }
    TEST(CarUnitTest, SurfaceSensorTest) {
        Location v; v.xLocation=55; v.yLocation=49;
        World world;
        Field bad_road(v);
        bad_road.setSurface_Condition(1);
        world.setField(bad_road);
        Car car1;
        SurfaceSensor road_condition;
        car1.setSpeed(2);
        car1.goRight(3);
        ASSERT_EQ(v.xLocation, car1.getLocation().xLocation);
        ASSERT_EQ(v.yLocation, car1.getLocation().yLocation);
        ASSERT_EQ(1, road_condition.getCondition(v, world));
    }
    TEST(CarUnitTest, ImprovedCarTest) {
        Location v; v.xLocation=55; v.yLocation=49;
        World world;
        Field field(v);
        field.setSurface_Condition(1);
        field.setHumidity(70);
        field.setIsBarrier(true);
        world.setField(field);
        ThinkingCar car1;
        car1.setSpeed(2);
        car1.goRight(3);
        ASSERT_EQ(v.xLocation, car1.getLocation().xLocation);
        ASSERT_EQ(v.yLocation, car1.getLocation().yLocation);
        ASSERT_EQ(1, car1.getSurfaceCondition(world));
        ASSERT_EQ(70, car1.getHumidityInfo(world));
        ASSERT_EQ(true, car1.getTouchInfo(world));
    }
    TEST(CarUnitTest, CarPower) {
        Location v; v.xLocation=55; v.yLocation=49;
        World world;
        Field field(v);
        field.setMinimal_Horsepower(200);
        ThinkingCar car1;
        car1.setSpeed(2);
        car1.goRight(3);
        ASSERT_EQ(v.xLocation, car1.getLocation().xLocation);
        ASSERT_EQ(v.yLocation, car1.getLocation().yLocation);
        ASSERT_EQ(false, car1.isEnoughPower(world));
    }
    TEST(CarUnitTest, CarPowerPassed) {
        Location v; v.xLocation=55; v.yLocation=49;
        World world;
        Field field(v);
        field.setMinimal_Horsepower(200);
        SensitiveStrongCar car1;
        car1.setSpeed(2);
        car1.goRight(3);
        ASSERT_EQ(v.xLocation, car1.getLocation().xLocation);
        ASSERT_EQ(v.yLocation, car1.getLocation().yLocation);
        ASSERT_EQ(false, car1.isEnoughPower(world));
    }
}