#include "LandingGear.hpp"
#include <sstream>

LandingGear::LandingGear(std::string id, std::string name, ComponentStatus status)
    : Component(id, name, status),
      structuralStress(0)
      {}

std::string LandingGear::getType() const {
    return "landingGear";
}

 std::string LandingGear::getDetails() const {
    std::string data = "";
    data += "structuralStress: " + std::to_string(structuralStress);
    return getComponentDetails(getType(), data); 
 }

 std::string LandingGear::getTypeDetails() const {
    std::string data = "";
    data += "structuralStress: " + std::to_string(structuralStress);
    return data; 
 }

 std::string LandingGear::getData() const {
    std::string data = "";
    data = data + std::to_string(structuralStress);
    return data;
 }

 //todo
 std::string LandingGear::checkValues() const {
    std::string ret = "Landing Gear values are within safe bounds";
    if (0 > structuralStress)
        ret = "WARNING: structuralStress is below minimum of 0";
    else if (structuralStress > 70000)
        ret = "WARNING: structuralStress is above maximum of 70000";
    return ret;
 }

 std::vector<std::string> LandingGear::getDataTypes() const {
    return {"structuralStress (double)"};
 }

 //todo
 std::string LandingGear::validateInput(std::vector<std::string> values) const {
    double stress;
    std::stringstream stressStream(values[0]);
    if (!(stressStream >> stress)) {
        return "Structural Stress must be a valid number.";
    }
    stressStream >> std::ws;
    if (!stressStream.eof() || !std::isfinite(stress)) {
        return "Structural stress must be a valid number.";
    }
    if (stress < 0 || stress > 100000) {
        return "Structural stress must be between 0 and 100000.";
    }
    
    return "";
 }

 std::string LandingGear::updateValues(std::vector<std::string> values)  {
    if (validateInput(values) != ""){
        return validateInput(values);
    }

    std::stringstream ss(values[0]);
    double stress;
    ss >> stress;

    structuralStress = stress;

    return "";
 }
