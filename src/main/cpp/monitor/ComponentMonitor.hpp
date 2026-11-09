#pragma once

#include <iostream>
#include "ComponentStorage.hpp"
#include "../component/ComponentFactory.hpp"

class ComponentMonitor {

    private:
        ComponentStorage storage;
        ComponentFactory factory;

    public:

        int main(void);

        void addComponent(std::string id, std::string name, ComponentStatus status, std::string type);

        void updateComponent(std::string id, ComponentStatus status);

        void deleteComponent(std::string id);

        void monitorComponent(std::string id);

        void displayAllComponents();

        void displayComponent(std::string id);


};