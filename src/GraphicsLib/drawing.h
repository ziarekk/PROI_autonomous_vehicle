#include "objects.h"
#include <memory>

/*
Autor: Karol Ziarek
*/

class Drawing{
    std::vector<std::unique_ptr<Object>> objects;
    std::vector<std::reference_wrapper<Object>> objectsReferences;
public:
    Drawing() = default;

    Drawing& operator+=(std::unique_ptr<Object> object){
        objects.push_back(std::move(object));
        objectsReferences = getObjects();
        return *this;
    }

    std::vector<std::reference_wrapper<Object>> getObjects(){
        std::vector<std::reference_wrapper<Object>> References;
        for (auto& pointer: objects){
            References.push_back(std::ref(*pointer));
        }
        return References;
    }

    std::reference_wrapper<Object> operator[](int index) const noexcept{
        return objectsReferences[index];
    }

    void display(){
        for(auto object: objectsReferences){
            object.get().draw();
        }
        clearDrawing();
        }

    void clearDrawing(){
        objects.clear();
        objectsReferences.clear();
        }


};
