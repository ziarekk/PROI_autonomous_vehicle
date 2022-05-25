#include <vector>

struct Location{
    int xLocation;
    int yLocation;
};

class Steering
{
private:
    int xLocation=49;
    int yLocation=49;
    int speed=0;
public:
    Location getLocation() const noexcept;
    int getSpeed() const noexcept;
    void setSpeed(int new_speed);
    void goLeft(int time);
    void goRight(int time);
    void goUp(int time);
    void goDown(int time);
};

class Field
{
private:
    int xLocation;
    int yLocation;
    bool isBarrier;
    int humidity;
    int surface_condition;
    int minimal_horsepower;
public:
    Field() noexcept;
    Field(Location location) noexcept;
    Location getLocation() const noexcept;
    bool getIsBarrier() const noexcept;
    void setIsBarrier(bool barrier);
    int getHumidity() const noexcept;
    void setHumidity(int hum);
    int getSurface_Condition() const noexcept;
    void setSurface_Condition(int condition);
    int getMinimal_Horsepower() const noexcept;
    void setMinimal_Horsepower(int HP);
};

class World
{
private:
    std::vector<std::vector<Field>> field_container;
public:
    World() noexcept;
    void setField(Field square);
    std::vector<std::vector<Field>> getFieldContainer() const noexcept;
    Field operator()(Location location) const noexcept;
};

class Sensor
{

};

class Car: public Steering
{
private:
    std::vector<Sensor> list_of_sensors;
    int horsepower;
    bool canDrive;
public:
    void setPower(int HP);
    int getPower(int HP);
    bool isEnoughPower(World world) noexcept;
};

class TouchSensor: public Sensor
{
private:
    bool isTouched;
public:
    bool getInfo(Location location, World world) noexcept;
};

class HumiditySensor
{
private:
    int humidity;
public:
    int getHumidity(Location location, World world) noexcept;
};

class SurfaceSensor: public Sensor
{
private:
    int surface_condition;
public:
    int getCondition(Location location, World world) noexcept;
};

class ThinkingCar: public Car
{
private:
    TouchSensor touch;
    HumiditySensor humidity;
    SurfaceSensor condition;
    int horsepower = 80;
public:
    bool getTouchInfo(World world) noexcept;
    int getHumidityInfo(World world) noexcept;
    int getSurfaceCondition(World world) noexcept;
};

class SensitiveStrongCar: public Car
{
private:
    TouchSensor touch;
    int horsepower = 250;
public:
    bool getTouchInfo(World world) noexcept;
};

class ThinkingStrongCar: public Car
{
private:
    TouchSensor touch;
    HumiditySensor humidity;
    SurfaceSensor condition;
    int horsepower = 300;
public:
    bool getTouchInfo(World world) noexcept;
    int getHumidityInfo(World world) noexcept;
    int getSurfaceCondition(World world) noexcept;
};