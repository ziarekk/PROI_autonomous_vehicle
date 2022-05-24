#include <iostream>
#include <vector>

using namespace std;

class Car
{
private:
    vector<int> attributes;
public:
    vector<int> getAttributes() const noexcept;
    void turnLeft() noexcept;
    void turnRight() noexcept;
    void accelerate() noexcept;
};
