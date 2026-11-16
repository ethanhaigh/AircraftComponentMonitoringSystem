#pragma once
#include "../component/Component.hpp"
#include "ComponentObserver.hpp"

class ComponentSubject {

    private:
    std::vector<ComponentObserver*> observers;

    public:

        void initialise();

        void receiveNotification(Component* component, std::string reason);


};