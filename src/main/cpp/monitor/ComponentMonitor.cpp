#include <iostream>
#include "../component/Component.hpp"
#include "Utility.hpp"
#include "ComponentStorage.hpp"
#include "../api/CommandLineController.hpp"
#include "ComponentMonitor.hpp"

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

void ComponentMonitor::updateComponent(std::string id, std::string status)
{

}

void ComponentMonitor::removeComponent(std::string id)
{

}

void ComponentMonitor::monitorComponent(std::string id)
{

}

void ComponentMonitor::displayComponent(std::string id)
{

}