#include <iostream>
#include "../component/Component.hpp"
#include "Utility.cpp"
#include "ComponentStorage.cpp"
#include "../api/CommandLineController.cpp"

class ComponentMonitor{

private:
    ComponentStorage storage;

public:

    int main(void)
    {

    }

    void addComponent(std::string id, std::string name, std::string type, std::string status)
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

    static void updateComponent(std::string id, std::string status)
    {

    }

    static void removeComponent(std::string id)
    {

    }

    static void monitorComponent(std::string id)
    {

    }

    static void displayComponent(std::string id)
    {

    }

}