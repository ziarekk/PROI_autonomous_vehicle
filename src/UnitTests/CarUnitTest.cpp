#include <gtest/gtest.h>
#include "Car.h"

namespace CarUnitTest {
    TEST(CarUnitTest, getSpeedTest1) {
        int loc[2] {49, 50};
        World world;
        Car car(loc, world, 5, 30);
        ASSERT_EQ(0, car.getSpeed());
        ASSERT_EQ(49, car.getLocation()[0]);
        ASSERT_EQ(50, car.getLocation()[1]);
        ASSERT_EQ(0, car.getSpeed());
        car.accelerate();
        ASSERT_EQ(5, car.getSpeed());
    }
    TEST(CarUnitTest, getSpeedTest2) {
        Car car;
        ASSERT_EQ(0, car.getSpeed());
        car.accelerate(); car.accelerate();
        car.accelerate(); car.accelerate();
        car.accelerate();
        ASSERT_EQ(20, car.getSpeed());
        car.accelerate();
        ASSERT_EQ(20, car.getSpeed());
    }
    TEST(CarUnitTest, turnLeftTest) {
        Car car;
        ASSERT_EQ('n', car.getDirection());
        car.turnLeft();
        ASSERT_EQ('w', car.getDirection());
    }
    TEST(CarUnitTest, turnRightTest) {
        Car car;
        ASSERT_EQ('n', car.getDirection());
        car.turnRight();
        ASSERT_EQ('e', car.getDirection());
    }
    TEST(CarUnitTest, brakeTest) {
        Car car;
        car.accelerate(); car.accelerate();
        ASSERT_EQ(8, car.getSpeed());
        car.brake();
        ASSERT_EQ(0, car.getSpeed());
    }
    TEST(CarUnitTest, BarrierEqualTest) {
        int v1[2] {49, 52};
        int v2[2] {49, 53};
        World world;
        Field bar(v2);
        bar.setIsBarrier(true);
        world.setField(bar);
        TouchSensor touch;
        touch.getInfo(v1, world);
        ASSERT_EQ(true, touch.getInfo(v1, world));
    }
    TEST(CarUnitTest, WorldConstructorTest) {
        World world;
        ASSERT_EQ(99, world.getFieldContainer()[99][99].getLocation()[0]);
    }
    TEST(CarUnitTest, HumiditySensorTest) {
        int v[2] {46, 49};
        World world;
        Field wet(v);
        wet.setHumidity(60);
        world.setField(wet);
        ThinkingCar car1(v, world);
        ASSERT_EQ(60, car1.getHumidityInfo());
    }
    TEST(CarUnitTest, SurfaceSensorTest) {
        int v[2] {46, 49};
        World world;
        Field bad_road(v);
        bad_road.setSurface_Condition(1);
        world.setField(bad_road);
        ThinkingCar car1(v, world);
        ASSERT_EQ(1, car1.getSurfaceCondition());
    }
    TEST(CarUnitTest, ImprovedCarTest) {
        int v1[2] {46, 49};
        int v2[2] {47, 49};
        World world;
        Field field2(v2);
        field2.setIsBarrier(true);
        world.setField(field2);
        ThinkingCar car1(v1, world);
        ASSERT_EQ(true, car1.getTouchInfo());
    }
    TEST(CarUnitTest, RadarTest) {
        int v1[2] {30, 49};
        int v2[2] {47, 49};
        World world;
        Field field(v1);
        field.setIsBarrier(true);
        world.setField(field);
        ThinkingCar car1(v2, world);
        car1.turnLeft();
        ASSERT_EQ('w', car1.getDirection());
        ASSERT_EQ(17, car1.getRadarInfo());
    }
}