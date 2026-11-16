#pragma once
#include "../ComponentObserver.hpp"

class MaintenanceObserver : public ComponentObserver {

    public:
        MaintenanceObserver();

        std::string getType() const override;

        void notify(Component* component, std::string reason) const override;
};