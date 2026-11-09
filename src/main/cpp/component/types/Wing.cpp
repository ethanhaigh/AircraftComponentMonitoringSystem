#include "Wing.hpp"
#include <sstream>

Wing::Wing(std::string id, std::string name, ComponentStatus status)
    : Component(id, name, status),
      deploymentCycles(0),
      deployed(false)
      {}

std::string Wing::getType() const {
    return "wing";
}

 std::string Wing::getDetails() const {
    //todo
 }

 std::string Wing::checkValues() const {
    //todo
 }

 std::vector<std::string> Wing::getDataTypes() const {
    return {"deploymentCycles (integer)", "deployed (boolean)"};
 }

 std::string Wing::validateInput(std::vector<std::string> values) const {
    try
    {
       std::stringstream ss(values[0]);
       int cycles;

       if (!(ss >> cycles) || ss.peek() != EOF)
            return "Deployment cycles must be a valid integer.";

        if (cycles < 0 || cycles > 100000)
            return "Deployment cycles must be between 0 and 100000.";
    }
    catch (...)
    {
        return "Deployment cycles must be a valid integer.";
    }

    if (values[1] != "true" && values[1] != "false")
        return "Deployed must be either true or false.";

    return "";
 }

 std::string Wing::updateValues(std::vector<std::string> values)  {
    if (validateInput(values) != ""){
        return validateInput(values);
    }

    std::stringstream ss(values[0]);
    int cycles;
    bool newDeployed = (values[1] == "true");

    deploymentCycles = cycles;
    deployed = newDeployed;

    return "";
 }
