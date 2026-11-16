#pragma once
#include "../ComponentObserver.hpp"

class AlertObserver : public ComponentObserver {

    public:
        AlertObserver();

        std::string getType() const override;

        void notify(Component* component, std::string reason) const override;
};