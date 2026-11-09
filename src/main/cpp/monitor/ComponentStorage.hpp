#pragma once

#include <iostream>
#include <vector>
#include "../component/Component.hpp"

class ComponentStorage {

private:
    std::vector<Component*> components;

public:
    Component* getComponent(std::string id);

    std::vector<Component*> getComponents();

    void setComponentData(Component* component);
    
    bool checkId(std::string id);
    
    bool checkName(std::string name);

    int getSize();

    bool addComponent(Component* component);

    bool updateComponent(Component* component);

    bool deleteComponent(std::string id);
    

};