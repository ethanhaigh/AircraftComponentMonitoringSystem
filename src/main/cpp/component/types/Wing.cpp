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
    std::string data = "";
    data += "deploymentCycles: " + std::to_string(deploymentCycles) + "\n";
    data += "deployed        : " + std::string(deployed ? "true" : "false");
    return getComponentDetails(getType(), data); 
 }

 std::string Wing::getTypeDetails() const {
    std::string data = "";
    data += "deploymentCycles: " + std::to_string(deploymentCycles) + "\n";
    data += "deployed        : " + std::string(deployed ? "true" : "false");
    return data; 
 }

 std::string Wing::getData() const {
    std::string data = "";
    data = data + std::to_string(deploymentCycles) + ",";
    data = data + std::string(deployed ? "true" : "false");
    return data;
 }

 std::string Wing::checkValues() const {
    std::string ret = "Wing values are within safe bounds";
    if (0 > deploymentCycles)
        ret = "WARNING: DeploymentCycles are below minimum of 0";
    else if (deploymentCycles > 100000)
        ret = "WARNING: DeploymentCycles are above maximum of 100000";
    return ret;
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
    ss >> cycles;
    bool newDeployed = (values[1] == "true");

    deploymentCycles = cycles;
    deployed = newDeployed;

    return "";
 }
