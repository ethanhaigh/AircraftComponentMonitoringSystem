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

void ComponentMonitor::addComponent(std::string id, std::string name, ComponentStatus status, std::string type)
{
    if (storage.checkId(id)) {
        CommandLineController::logIdInUse(id);
        return;
    }
    if (storage.checkName(name)) {
        CommandLineController::logNameInUse(name);
        return;
    }
    Component* component = factory.createComponent(type, id, name, status);
    if (component == nullptr) {
        CommandLineController::logFailedAdd(id, name, type, Utility::convertToString(status));
        return;
    }
    storage.setComponentData(component);
    if (storage.addComponent(component))
    {
        CommandLineController::logSuccessfulAdd(id, name, type, Utility::convertToString(status));
        return;
    }
    CommandLineController::logFailedAdd(id, name, type, Utility::convertToString(status));
}

void ComponentMonitor::updateComponent(std::string id, ComponentStatus status)
{
    Component* component = storage.getComponent(id);
    component->setStatus(status);
    storage.setComponentData(component);
    if (storage.updateComponent(component))
    {
        CommandLineController::logSuccessfulUpdate(id, Utility::convertToString(status));
        return;
    }
    CommandLineController::logFailedUpdate(id, Utility::convertToString(status));

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
    Component* component = storage.getComponent(id);
    std::string result = component->checkValues();
    if (result.rfind("WARNING", 0) == 0) {
        component->setStatus(ComponentStatus::Warning);
        storage.updateComponent(component);
    }
    CommandLineController::logMonitorResult(result);

}

void ComponentMonitor::displayAllComponents()
{
    std::vector<Component*> components = storage.getComponents();

    for (int i = 0; i  < components.size(); i++){
        CommandLineController::displayComponent(components[i]->getDetails());
    }
}

void ComponentMonitor::displayComponent(std::string id)
{
    Component* component = storage.getComponent(id);
    
    CommandLineController::displayComponent(component->getDetails());
}