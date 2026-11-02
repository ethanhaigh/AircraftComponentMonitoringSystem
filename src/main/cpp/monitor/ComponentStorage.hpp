#pragma once

#include <iostream>
#include <vector>
#include "../component/Component.hpp"

class ComponentStorage {

private:
    std::vector<std::unique_ptr<Component>> components;

public:
    Component* getComponent(std::string id);
    
    bool checkId(std::string id);
    
    bool checkName(std::string name);

};