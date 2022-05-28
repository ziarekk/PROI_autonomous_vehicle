//#include <gtest/gtest.h>
//#include "Car.h"
//
//namespace {
//    TEST(CarUnitTest, getSpeedTest1) {
//        Position loc {49, 50};
//        Car car(loc, 30);
//        ASSERT_EQ(0, car.getSpeed());
//        ASSERT_EQ(49, car.getLocation().x);
//        ASSERT_EQ(50, car.getLocation().y);
//        ASSERT_EQ(0, car.getSpeed());
//        car.accelerate(5);
//        ASSERT_EQ(5, car.getSpeed());
//    }
//    TEST(CarUnitTest, getSpeedTest2) {
//        Position pos;
//        Car car(pos);
//        ASSERT_EQ(0, car.getSpeed());
//        car.accelerate(20);
//        ASSERT_EQ(20, car.getSpeed());
//        car.accelerate(30);
//        ASSERT_EQ(20, car.getSpeed());
//    }
//    TEST(CarUnitTest, turnLeftTest) {
//        Position pos;
//        Car car(pos);
//        ASSERT_EQ('n', car.getDirection());
//        car.turnLeft();
//        ASSERT_EQ('w', car.getDirection());
//    }
//    TEST(CarUnitTest, turnRightTest) {
//        Position pos;
//        Car car(pos);
//        ASSERT_EQ('n', car.getDirection());
//        car.turnRight();
//        ASSERT_EQ('e', car.getDirection());
//    }
//    TEST(CarUnitTest, brakeTest) {
//        Position pos;
//        Car car(pos);
//        car.accelerate(8);
//        ASSERT_EQ(8, car.getSpeed());
//        car.brake();
//        ASSERT_EQ(0, car.getSpeed());
//    }
//    TEST(CarUnitTest, BarrierEqualTest) {
//        Position v1 {10, 10};
//        Position v2 {11, 10};
//        Map world;
//        Field bar(v2);
//        bar.setIsBarrier(true);
//        world.setField(bar);
//        TouchSensor touch;
//        touch.getIsTouched(v1, world);
//        ASSERT_EQ(true, touch.getIsTouched(v1, world));
//    }
//    TEST(CarUnitTest, WorldConstructorTest) {
//        Map world;
//        ASSERT_EQ(19, world.getFieldContainer()[19][19].getLocation().x);
//    }
//    TEST(CarUnitTest, HumiditySensorTest) {
//        Position v {10, 10};
//        Map world;
//        Field wet(v);
//        wet.setHumidity(60);
//        world.setField(wet);
//        HumiditySensor sens;
//        ASSERT_EQ(60, sens.getInfo(v, world));
//    }
//    TEST(CarUnitTest, SurfaceCarTest) {
//        Position v {10, 10};
//        Map world;
//        Field bad_road(v);
//        bad_road.setSurface_Condition(1);
//        world.setField(bad_road);
//        ThinkingCar car1(v, world);
//        ASSERT_EQ(1, car1.getSurfaceCondition());
//    }
//    TEST(CarUnitTest, SurfaceSensorTest) {
//        Position v {10, 10};
//        Map world;
//        Map& map = world;
//        Field bad_road(v);
//        bad_road.setSurface_Condition(1);
//        world.setField(bad_road);
//        SurfaceSensor sen;
//        ASSERT_EQ(1, sen.getInfo(v, map));
//    }
//    TEST(CarUnitTest, AttributesTest) {
//        Position v1 {10, 11};
//        Map world;
//        Field field1(v1);
//        field1.setTemperature(20);
//        field1.setHumidity(60);
//        field1.setSurface_Condition(1);
//        world.setField(field1);
//        ThinkingCar car1(v1, world);
//        ASSERT_EQ(20, car1.getAttributes()[0]);
//        ASSERT_EQ(60, car1.getAttributes()[1]);
//        ASSERT_EQ(1, car1.getAttributes()[2]);
//    }
//    TEST(CarUnitTest, RadarTest) {
//        Position v1 {2, 10};
//        Position v2 {14, 10};
//        Map world;
//        Field field(v1);
//        field.setIsBarrier(true);
//        world.setField(field);
//        ThinkingCar car1(v2, world);
//        car1.turnLeft();
//        ASSERT_EQ('w', car1.getDirection());
//        std::vector<int> result = car1.getRadarInfo();
//        ASSERT_EQ(12, result[0]);
//    }
//    TEST(CarUnitTest, ImprovedCarTest) {
//        Position v1{10, 11};
//        Position v2{10, 10};
//        Map world;
//        Field field2(v2);
//        field2.setIsBarrier(true);
//        world.setField(field2);
//        ThinkingCar car1(v1, world);
//        ASSERT_EQ(true, car1.getTouchInfo());
//    }
//}