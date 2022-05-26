#include <vector>

class Field
{
private:
    int xLocation;
    int yLocation;
    bool isBarrier=false;
    int humidity;
    int surface_condition;
public:
    Field() noexcept;
    Field(int* location) noexcept;
    int* getLocation() const noexcept;
    bool getIsBarrier() const noexcept;
    void setIsBarrier(bool barrier);
    int getHumidity() const noexcept;
    void setHumidity(int hum);
    int getSurface_Condition() const noexcept;
    void setSurface_Condition(int condition);
};

class World
{
private:
    std::vector<std::vector<Field>> field_container;
public:
    World() noexcept;
    void setField(Field square);
    std::vector<std::vector<Field>> getFieldContainer() const noexcept;
    Field operator()(int* location) const noexcept;
};
