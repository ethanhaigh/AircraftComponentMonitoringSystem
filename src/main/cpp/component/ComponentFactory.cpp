#include <iostream>
#include "ComponentFactory.hpp"
#include "../monitor/Utility.hpp"
#include "types/Engine.hpp"
#include "types/LandingGear.hpp"
#include "types/Wing.hpp"
#include "ComponentStatus.hpp"

ComponentFactory::ComponentFactory() {
    componentTypes = {
        {"engine",
            [](const std::string id, const std::string name, const ComponentStatus status) { return new Engine(id, name, status); }},

        {"landinggear",
             [](const std::string id, const std::string name, const ComponentStatus status) { return new LandingGear(id, name, status); }},

        {"wing",
             [](const std::string id, const std::string name, const ComponentStatus status) { return new Wing(id, name, status); }}
    };
}

Component* ComponentFactory::createComponent(const std::string type, std::string id, std::string name, ComponentStatus status)  {
    auto iterator = componentTypes.find(Utility::convertToLowercase(type));
    if (iterator == componentTypes.end()) {
        return nullptr;
    }
    return iterator->second(id, name, status);
}