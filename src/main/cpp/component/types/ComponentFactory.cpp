#include "../ComponentFactory.hpp"
#include "../../monitor/Utility.hpp"
#include "Engine.hpp"
#include "LandingGear.hpp"
#include "Wing.hpp"

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