#pragma once
#include <iostream>
#include "../component/Component.hpp"

class ComponentObserver {

    public:

        virtual ~ComponentObserver() = default;

        virtual std::string getType() const = 0;

        virtual void notify(Component* component, std::string reason) const = 0;

};