#include <iostream>
#include "../component/Component.hpp"
#include "Utility.hpp"
#include "ComponentStorage.hpp"
#include "InputParser.hpp"
#include "../api/CommandLineController.hpp"
#include "ComponentMonitor.hpp"
#include "../component/ComponentStatus.hpp"
#include "../alert/ComponentSubject.hpp"

int ComponentMonitor::run()
{
    Utility::extractComponents("src/main/resources/components.csv", *this);
    InputParser parser(*this);
    subject.initialise();
    CommandLineController controller(*this, parser);
    controller.initialise();
    return 0;
}

int main()
{
    ComponentMonitor monitor;
    return monitor.run();
}

void ComponentMonitor::quit()
{
    Utility::writeComponents("src/main/resources/components.csv", storage.getComponents());
    exit(0);
}

ComponentMonitor ComponentMonitor::getMonitor()
{
    return ComponentMonitor{};
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
    if (!storage.setComponentData(component))
    {
        return;
    };
    if (storage.addComponent(component))
    {
        CommandLineController::logSuccessfulAdd(component->getDetails());
        return;
    }
    CommandLineController::logFailedAdd(component->getDetails());
}

void ComponentMonitor::updateComponent(std::string id, ComponentStatus status)
{
    Component* component = storage.getComponent(id);
    component->setStatus(status);
    if (!storage.setComponentData(component))
    {
        return;
    };
    if (storage.updateComponent(component))
    {
        CommandLineController::logSuccessfulUpdate(component->getDetails());
        return;
    }
    CommandLineController::logFailedUpdate(component->getDetails());

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
        subject.receiveNotification(component, result);
    }
    if ((Utility::convertToString(component->getStatus())) != "Normal") {
        subject.receiveNotification(component, "maintenance");
    } else {
        CommandLineController::logMonitorResult(result);
    }

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

    if (component == nullptr)
    {
        return;
    }
    
    CommandLineController::displayComponent(component->getDetails());
}

Component* ComponentMonitor::addExistingComponent(std::string id, std::string name, ComponentStatus status, std::string type)
{
    Component* component = factory.createComponent(type, id, name, status);
    if (component != nullptr) {
        storage.addComponent(component);
    }
    return component;
}

std::vector<std::string> ComponentMonitor::getTypes()
{
    return factory.getTypes();
}