#include <gtest/gtest.h>
#include "Driver.h"
#include "../CarExample/Car.h"

using namespace std;

TEST(Driver, Constructor)
{
    vector<int> pos = {0, 0};
    vector<int> dest = {5, 5};
    vector<int> distances = {10, 20, 20};
    vector<int> attr = {9, 20, 40};
    Driver<Car> dv(pos, 's', dest, distances, attr);
    ASSERT_EQ(dv.getDestination(), dest);
    ASSERT_EQ(dv.getDirection(), 's');
    ASSERT_EQ(dv.getWallDistances(), distances);
    ASSERT_EQ(dv.getRoadQuality(), attr[0]);
    ASSERT_EQ(dv.getTemperature(), attr[1]);
    ASSERT_EQ(dv.getHumidity(), attr[2]);
}

TEST(Driver, updatePos)
{
    vector<int> new_pos = {2, 2};
    vector<int> new_dist = {10, 18, 20};
    vector<int> new_attr = {9, 20, 40};
    char new_dir = 'e';
    Driver<Car> dv(vector<int> {0, 0}, 's', vector<int> {5, 5}, vector<int> {10, 20, 20}, vector<int> {9, 20, 40});
    dv.updatePosition(new_pos, new_dir, new_dist, new_attr);
    ASSERT_EQ(dv.getDirection(), 'e');
    ASSERT_EQ(dv.getWallDistances(), new_dist);
}

TEST(Driver, navigate_end)
{
    Car car('s');
    Driver<Car> dv(vector<int> {5, 5}, 's', vector<int> {5, 5}, vector<int> {10, 20, 20}, vector<int> {9, 20, 40});
    dv.navigate(car);
    ASSERT_EQ(dv.getSpeed(), 0);
}

TEST(Driver, navigate_turnLeft_v1)
{
    Car car('s');
    Driver<Car> dv(vector<int> {4, 4}, 's', vector<int> {5, 5}, vector<int> {10, 20, 20}, vector<int> {9, 20, 40});
    dv.navigate(car);
    ASSERT_EQ(dv.getSpeed(), 50);
    ASSERT_EQ(car.getDirection(), 'e');
}

TEST(Driver, navigate_turnLeft_v2)
{
    Car car('n');
    Driver<Car> dv(vector<int> {7, 7}, 'n', vector<int> {5, 5}, vector<int> {10, 20, 20}, vector<int> {9, 20, 40});
    dv.navigate(car);
    ASSERT_EQ(dv.getSpeed(), 50);
    ASSERT_EQ(car.getDirection(), 'w');
}

TEST(Driver, navigate_turnRight_v1)
{
    Car car('n');
    Driver<Car> dv(vector<int> {4, 4}, 'n', vector<int> {5, 5}, vector<int> {10, 20, 20}, vector<int> {9, 20, 40});
    dv.navigate(car);
    ASSERT_EQ(dv.getSpeed(), 50);
    ASSERT_EQ(car.getDirection(), 'e');
}

TEST(Driver, navigate_turnRight_v2)
{
    Car car('s');
    Driver<Car> dv(vector<int> {8, 8}, 's', vector<int> {7, 7}, vector<int> {10, 20, 20}, vector<int> {9, 20, 40});
    dv.navigate(car);
    ASSERT_EQ(dv.getSpeed(), 50);
    ASSERT_EQ(car.getDirection(), 'w');
}

TEST(Driver, navigate_noChange_v1)
{
    Car car('w');
    Driver<Car> dv(vector<int> {8, 9}, 'w', vector<int> {7, 7}, vector<int> {10, 20, 20}, vector<int> {9, 20, 40});
    dv.navigate(car);
    ASSERT_EQ(dv.getSpeed(), 50);
    ASSERT_EQ(car.getDirection(), 'w');
}

TEST(Driver, navigate_noChange_v2)
{
    Car car('e');
    Driver<Car> dv(vector<int> {4, 7}, 'e', vector<int> {7, 7}, vector<int> {10, 20, 20}, vector<int> {9, 20, 40});
    dv.navigate(car);
    ASSERT_EQ(dv.getSpeed(), 50);
    ASSERT_EQ(car.getDirection(), 'e');
}

TEST(Driver, navigate_avoidWall_go_left)
{
    Car car('n');
    Driver<Car> dv(vector<int> {4, 7}, 'n', vector<int> {7, 7}, vector<int> {2, 25, 20}, vector<int> {9, 20, 40});
    dv.navigate(car);
    ASSERT_EQ(dv.getSpeed(), 50);
    ASSERT_EQ(car.getDirection(), 'w');
}

TEST(Driver, navigate_avoidWall_go_right)
{
    Car car('e');
    Driver<Car> dv(vector<int> {4, 7}, 'e', vector<int> {7, 7}, vector<int> {1, 16, 21}, vector<int> {9, 20, 40});
    dv.navigate(car);
    ASSERT_EQ(dv.getSpeed(), 50);
    ASSERT_EQ(car.getDirection(), 's');
}
