#include <iostream>
#include <vector>
#include "../component/ComponentStatus.hpp"
#include "../component/Component.hpp"
#include "../api/CommandLineController.hpp"
#include "ComponentStorage.hpp"
#include <cctype>

Component* ComponentStorage::getComponent(std::string id)
{
    for  (const auto& component : components) {
        if (component->getId() == id) {
            return component.get();
        }
    }
    CommandLineController::logComponentNotFound(id);
    return nullptr;
}

bool ComponentStorage::checkId(std::string id)
{
    bool found = false;
    for  (const auto& component : components) {
        if (component->getId() == id) {
            found = true;
        }
    }
    return found;
}

bool ComponentStorage::checkName(std::string name)
{
    bool found = false;
    for  (const auto& component : components) {
        if (component->getName() == name) {
            found = true;
        }
    }
    return found;
}