#pragma once
#include <iostream>
#include "../Component.hpp"

class Engine : public Component {

    private:
        double temperature;
        double vibrationLevel;

    public:
        Engine();

        std::string getDetails() const override;

        std::string checkValues() const override;
}