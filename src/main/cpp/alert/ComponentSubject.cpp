#include <iostream>
#include "ComponentSubject.hpp"
#include "ComponentObserver.hpp"
#include "types/MaintenanceObserver.hpp"
#include "types/AlertObserver.hpp"

void ComponentSubject::initialise() {
    ComponentObserver* maintenance = new MaintenanceObserver();
    ComponentObserver* alert = new AlertObserver();

    observers.push_back(maintenance);
    observers.push_back(alert);
}

void ComponentSubject::receiveNotification(Component* component, std::string reason) {
    for  (const auto& observer : observers) {
        observer->notify(component, reason);
    }
    
}