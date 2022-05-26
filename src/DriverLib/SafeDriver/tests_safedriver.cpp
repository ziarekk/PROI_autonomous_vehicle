// #include <gtest/gtest.h>
// #include "../CarLib/Car.h"
// #include "../MapLib/Position.h"
// #include "SafeDriver.h"

// using namespace std;

// TEST(SafeDriver, calculateSpeed_bad_road)
// {
//     Car car('s');
//     SafeDriver sd(Position(), 's', Position(4, 4), vector<int> {10, 20, 20}, vector<int> {4, 15, 40});
//     ASSERT_EQ(sd.getSpeed(), 75);
// }

// TEST(SafeDriver, calculateSpeed_good_road)
// {
//     Car car('s');
//     SafeDriver sd(Position(), 's', Position(4, 4), vector<int> {10, 20, 20}, vector<int> {7, 15, 40});
//     ASSERT_EQ(sd.getSpeed(), 150);
// }

// TEST(SafeDriver, calculateSpeed_temp_zero)
// {
//     Car car('s');
//     SafeDriver sd(Position(), 's', Position(4, 4), vector<int> {10, 20, 20}, vector<int> {4, 0, 40});
//     ASSERT_EQ(sd.getSpeed(), 67);
// }

// TEST(SafeDriver, calculateSpeed_temp_minus)
// {
//     Car car('s');
//     SafeDriver sd(Position(), 's', Position(4, 4), vector<int> {10, 20, 20}, vector<int> {4, -10, 40});
//     ASSERT_EQ(sd.getSpeed(), 52);
// }

// TEST(SafeDriver, calculateSpeed_high_humidity)
// {
//     Car car('s');
//     SafeDriver sd(Position(), 's', Position(4, 4), vector<int> {10, 20, 20}, vector<int> {4, 15, 85});
//     ASSERT_EQ(sd.getSpeed(), 60);
// }

// TEST(SafeDriver, calculateSpeed_very_high_humidity)
// {
//     Car car('s');
//     SafeDriver sd(Position(), 's', Position(4, 4), vector<int> {10, 20, 20}, vector<int> {4, 20, 98});
//     ASSERT_EQ(sd.getSpeed(), 60);
// }
