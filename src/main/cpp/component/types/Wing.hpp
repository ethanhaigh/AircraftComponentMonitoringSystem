#pragma once
#include <iostream>
#include "../Component.hpp"
#include "../ComponentStatus.hpp"

class Wing : public Component {

    private:
        int deploymentCycles;
        bool deployed;

    public:
        Wing(std::string id, std::string name, ComponentStatus status);

        std::string getType() const override;

        std::string getDetails() const override;

        std::string checkValues() const override;

        std::vector<std::string> getDataTypes() const override;

        std::string validateInput(std::vector<std::string> values) const override;

        std::string updateValues(std::vector<std::string> values) override;
};