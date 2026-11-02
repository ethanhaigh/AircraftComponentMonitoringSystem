#pragma once

#include <iostream>
#include <map>
#include <functional>
#include "Component.hpp"

class ComponentFactory {

    private:
        std::map<std::string, std::function<std::unique_ptr<Component>()>> componentTypes;

    public:
        ComponentFactory();

        static std::unique_ptr<Component> createComponent(const std::string& type);

}