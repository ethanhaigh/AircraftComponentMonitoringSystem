#include <iostream>
#include "../component/Component.hpp"
#include "Utility.hpp"
#include "ComponentStorage.hpp"
#include "../api/CommandLineController.hpp"
#include "ComponentMonitor.hpp"
#include "../component/ComponentStatus.hpp"

int main(void)
{

}

void ComponentMonitor::addComponent(std::string id, std::string name, std::string type, std::string status)
{
    // verify id and name aren't already in use
    if (storage.checkId(id)) {
        CommandLineController::logIdInUse(id);
        return;
    }
    if (storage.checkName(name)) {
        CommandLineController::logNameInUse(name);
        return;
    }
    
}

void ComponentMonitor::updateComponent(std::string id, std::string statusName)
{
    Component* component = storage.getComponent(id);
    ComponentStatus status = Utility::convertToStatus(statusName);
    component->setStatus(status);
    if (storage.updateComponent(std::unique_ptr<Component>(component)))
    {
        CommandLineController::logSuccessfulUpdate(id, statusName);
        return;
    }
    CommandLineController::logFailedUpdate(id, statusName);

}

void ComponentMonitor::deleteComponent(std::string id)
{
    if (storage.deleteComponent(id))
    {
        CommandLineController::logSuccessfulDelete(id);
        return;
    }
    CommandLineController::logFailedDelete(id);
}

void ComponentMonitor::monitorComponent(std::string id)
{
    
}

void ComponentMonitor::displayComponent(std::string id)
{

}