#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "../DriverLib/Driver.h"
#include "../DriverLib/Car.h"

using namespace std;

TEST(Basic_Driver, Constructor)
{
    Car car;
    ASSERT_EQ(car.getDirection(), 's');
}
