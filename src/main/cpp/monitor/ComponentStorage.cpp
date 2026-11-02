#include <iostream>
#include <vector>
#include "../component/ComponentStatus.hpp"
#include "../component/Component.hpp"
#include "../api/CommandLineController.cpp"
#include <cctype>

class ComponentStorage {

private:
    std::vector<std::unique_ptr<Component>> components;


public:
    Component* getComponent(std::string id)
    {
        for  (const auto& component : components) {
            if (component->getId() == id) {
                return component;
            }
        }
        CommandLineController::logComponentNotFound(id);
    }
    
    bool checkId(std::string id)
    {
        bool found = false;
        for  (const auto& component : components) {
            if (component->getId() == id) {
                found = true;
            }
        }
        return found;
    }
    
    bool checkName(std::string name)
    {
        bool found = false;
        for  (const auto& component : components) {
            if (component->getName() == name) {
                found = true;
            }
        }
        return found;
    }

};