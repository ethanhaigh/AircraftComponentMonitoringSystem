#pragma once

#include <iostream>
#include "ComponentStorage.hpp"

class ComponentMonitor {

    private:
        ComponentStorage storage; 


    public:

        int main(void);

        void addComponent(std::string id, std::string name, std::string type, std::string status);

        void updateComponent(std::string id, std::string status);

        void deleteComponent(std::string id);

        void monitorComponent(std::string id);

        void displayComponent(std::string id);


};