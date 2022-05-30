#include "gtest/gtest.h"
#include "map.h"

namespace {
    TEST(MapUnitTest, fieldConstruction) {
        Position pos(10, 2);
        Field field(pos, true, 33, 1, 44);
        ASSERT_EQ(10, field.location.x);
        ASSERT_EQ(2, field.location.y);
        ASSERT_EQ(true, field.isBarrier);
        ASSERT_EQ(33, field.humidity);
        ASSERT_EQ(1, field.surface_condition);
        ASSERT_EQ(44, field.temperature);
    }
    TEST(MapUnitTest, createMap1) {
        Map map;
        ASSERT_EQ(0, map.getFieldContainer().size());
        std::vector<Field> v1;
        Position pos(0, 0);
        Field field(pos, true, 33, 1, 44);
        v1.push_back(field);
        std::vector<std::vector<Field>> v2;
        v2.push_back(v1);
        map.setFieldContainer(v2);
        ASSERT_EQ(1, map.getFieldContainer().size());
        ASSERT_EQ(true, map.getFieldContainer()[0][0].isBarrier);
        ASSERT_EQ(33, map.getFieldContainer()[0][0].humidity);
    }
    TEST(MapUnitTest, createMap2) {
        Map map(10, 10);
        ASSERT_EQ(10, map.getFieldContainer().size());
        ASSERT_EQ(60, map.getFieldContainer()[0][0].humidity);
        Position pos(9, 2);
        Field field(pos, true, 33, 1, 44);
        map.setField(field);
        ASSERT_EQ(true, map(pos).isBarrier);
        ASSERT_EQ(1, map(pos).surface_condition);
    }
    TEST(MapUnitTest, MapFileConstructor1) {
        Map map("test_map.txt");
        ASSERT_EQ(3, map.getFieldContainer().size());
        ASSERT_EQ(false, map.getFieldContainer()[0][0].isBarrier);
        ASSERT_EQ(20, map.getFieldContainer()[0][1].humidity);
        ASSERT_EQ(3, map.getFieldContainer()[2][2].temperature);
    }
    TEST(MapUnitTest, MapFileReader1) {
        Map map;
        map.read_from_file("test_map.txt");
        ASSERT_EQ(3, map.getFieldContainer().size());
        ASSERT_EQ(false, map.getFieldContainer()[0][0].isBarrier);
        ASSERT_EQ(20, map.getFieldContainer()[0][1].humidity);
        ASSERT_EQ(3, map.getFieldContainer()[2][2].temperature);
    }
    TEST(MapUnitTest, MapFileConstructor2) {
        Map map("test1.txt");
        ASSERT_EQ(4, map.getFieldContainer().size());
        ASSERT_EQ(false, map.getFieldContainer()[1][1].isBarrier);
        ASSERT_EQ(24, map.getFieldContainer()[3][2].humidity);
        ASSERT_EQ(22, map.getFieldContainer()[1][3].temperature);
    }

    TEST(MapUnitTest, MapFileReader2) {
        Map map;
        map.read_from_file("test1.txt");
        ASSERT_EQ(4, map.getFieldContainer().size());
        ASSERT_EQ(true, map.getFieldContainer()[1][2].isBarrier);
        ASSERT_EQ(24, map.getFieldContainer()[3][2].humidity);
        ASSERT_EQ(22, map.getFieldContainer()[1][3].temperature);
    }
}