#include "MaintenanceObserver.hpp"
#include "../../component/Component.hpp"
#include "../../api/CommandLineController.hpp"

MaintenanceObserver::MaintenanceObserver()
{
}

std::string MaintenanceObserver::getType() const {
    return "maintenance";
}

void MaintenanceObserver::notify(Component* component, std::string reason) const {
    if (reason != "maintenance") {
        return;
    }
    CommandLineController::logComponentNeedsMaintenance(component->getId(), component->getName(), component->getType(), component->getStatus());
}