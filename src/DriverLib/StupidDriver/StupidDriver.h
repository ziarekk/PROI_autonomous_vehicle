#pragma once
#include <iostream>
#include <vector>
#include "../BaseDriver/Driver.h"


class StupidDriver : public Driver
{
public:
    StupidDriver(Car &car) noexcept;
    void navigate(Car &car) noexcept;
};
