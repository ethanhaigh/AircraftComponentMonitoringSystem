#pragma once
#include "ComponentStatus.hpp"

class Component {

protected:
    std::string componentId;
    std::string name;
    ComponentStatus status;


public:
    virtual ~Component() = default;

    std::string getId() {
        return componentId;
    }

    std::string getName()  {
        return name;
    }

    ComponentStatus getStatus(){
        return status;
    }

    void setStatus(ComponentStatus newStatus){
        status = newStatus;
    }

    virtual std::string getDetails() const = 0;

    virtual std::string checkValues() const = 0;
};