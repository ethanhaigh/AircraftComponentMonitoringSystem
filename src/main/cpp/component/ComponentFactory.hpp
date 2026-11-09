#pragma once

#include <iostream>
#include <map>
#include <functional>
#include "Component.hpp"
#include  "ComponentStatus.hpp"

class ComponentFactory {

    private:
        std::map<std::string, std::function<Component* (const std::string, const std::string, const ComponentStatus)>> componentTypes;

    public:
        ComponentFactory();

        Component* createComponent(const std::string type, std::string id, std::string name, ComponentStatus status);

};