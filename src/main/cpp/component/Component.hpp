#pragma once
#include <iostream>
#include "ComponentStatus.hpp"
#include "../monitor/Utility.hpp"
#include <vector>

class Component {

protected:
    std::string componentId;
    std::string name;
    ComponentStatus status;
public:
    Component(std::string id, std::string name, ComponentStatus status);

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

    std::string getComponentDetails(std::string type, std::string data) const
    {
        std::string out = "";
        out = out + "id    : " + componentId + "\n";
        out = out + "name  : " + name + "\n";
        out = out + "type  : " + type + "\n";
        out = out + "status: " + Utility::convertToString(status) + "\n";
        out = out + data;
        return out;
    }

    virtual std::string getType() const = 0;

    virtual std::string getDetails() const = 0;

    virtual std::string getTypeDetails() const = 0;

    virtual std::string getData() const = 0;

    virtual std::string checkValues() const = 0;

    virtual std::vector<std::string> getDataTypes() const = 0;

    virtual std::string validateInput(std::vector<std::string> values) const = 0;

    virtual std::string updateValues(std::vector<std::string> values) = 0;
};