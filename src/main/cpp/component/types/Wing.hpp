#pragma once
#include <iostream>
#include "../Component.hpp"

class Wing : public Component {

    private:
        int deploymentCycles;
        bool deployed;

    public:
        Wing();

        std::string getDetails() const override;

        std::string checkValues() const override;
}