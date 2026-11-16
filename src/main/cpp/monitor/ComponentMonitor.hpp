#pragma once

#include <iostream>
#include "ComponentStorage.hpp"
#include "../component/ComponentFactory.hpp"
#include "../alert/ComponentSubject.hpp"

class ComponentMonitor {

    private:
        ComponentStorage storage;
        ComponentFactory factory;
        ComponentSubject subject;

    public:

        int run();

        void quit();
        
        ComponentMonitor getMonitor();

        void addComponent(std::string id, std::string name, ComponentStatus status, std::string type);

        void updateComponent(std::string id, ComponentStatus status);

        void deleteComponent(std::string id);

        void monitorComponent(std::string id);

        void displayAllComponents();

        void displayComponent(std::string id);

        Component* addExistingComponent(std::string id, std::string name, ComponentStatus status, std::string type);

        std::vector<std::string> getTypes();


};