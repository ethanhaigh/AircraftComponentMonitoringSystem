#include "ComponentFactory.hpp"
#include "../monitor/Utility.hpp"
#include "types/Engine.hpp"
#include "types/LandingGear.hpp"
#include "types/Wing.hpp"

ComponentFactory::ComponentFactory() {
    componentTypes = {
        {"engine",
            []() { return std::make_unique<Engine>(); }},

        {"landinggear",
             []() { return std::make_unique<LandingGear>(); }},

        {"wing",
             []() { return std::make_unique<Wing>(); }}
    };
}

std::unique_ptr<Component> ComponentFactory::createComponent(const std::string& type)  {
    auto iterator = componentTypes.find(Utility::convertToLowercase(type));

}