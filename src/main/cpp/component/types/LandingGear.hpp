#pragma once
#include <iostream>
#include "../Component.hpp"

class LandingGear : public Component {

    private:
        double structuralStress;
        
    public:
        LandingGear();

        std::string getDetails() const override;

        std::string checkValues() const override;
}