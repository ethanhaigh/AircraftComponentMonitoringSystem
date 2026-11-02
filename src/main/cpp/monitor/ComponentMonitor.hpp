#pragma once

#include <iostream>
#include "ComponentStorage.hpp"

class ComponentMonitor {

    private:
        ComponentStorage storage; 


    public:

        int main(void);

        static void addComponent(std::string id, std::string name, std::string type, std::string status);

        static void updateComponent(std::string id, std::string status);

        static void removeComponent(std::string id);

        static void monitorComponent(std::string id);

        static void displayComponent(std::string id);


}