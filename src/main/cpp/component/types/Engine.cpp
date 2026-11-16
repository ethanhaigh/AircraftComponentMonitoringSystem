#include "Engine.hpp"
#include <cmath>
#include <sstream>

Engine::Engine(std::string id, std::string name, ComponentStatus status)
    : Component(id, name, status),
      temperature(0),
      vibrationLevel(0)
      {}

std::string Engine::getType() const {
    return "engine";
}

 std::string Engine::getDetails() const {
    std::string data = "";
    data += "temperature: " + std::to_string(temperature) + "\n";
    data += "vibrationLevel: " + std::to_string(vibrationLevel);
    return getComponentDetails(getType(), data); 
 }

 std::string Engine::getTypeDetails() const {
    std::string data = "";
    data += "temperature: " + std::to_string(temperature) + "\n";
    data += "vibrationLevel: " + std::to_string(vibrationLevel);
    return data;
 }

 std::string Engine::getData() const {
    std::string data = "";
    data = data + std::to_string(temperature) + ",";
    data = data + std::to_string(vibrationLevel);
    return data;
 }

 //todo
 std::string Engine::checkValues() const {
    std::string ret = "Engine values are within safe bounds";
    if (0 > temperature)
        ret = "WARNING: temperature is below minimum of 0";
    else if (temperature > 900)
        ret = "WARNING: temperature is above maximum of 900";
    else if (0 > vibrationLevel)
        ret = "WARNING: vibrationLevel is below minimum of 0 mm/s";
    else if (vibrationLevel > 10)
        ret = "WARNING: vibrationLevel is above maximum of 10 mm/s";
    return ret;
 }

 std::vector<std::string> Engine::getDataTypes() const {
    return {"temperature (double)","vibrationLevel (double)"};
 }

 std::string Engine::validateInput(std::vector<std::string> values) const {

    double temperature;
    if (values[0] != "") {
        std::stringstream temperatureStream(values[0]);
        if (!(temperatureStream >> temperature)) {
            return "Temperature must be a valid number.";
        }

        temperatureStream >> std::ws;
        if (!temperatureStream.eof() || !std::isfinite(temperature)) {
            return "Temperature must be a valid number.";
        }
        if (temperature < 0 || temperature > 100000) {
            return "Temperature must be between 0 and 100000.";
        }
    }

    double vibrationLevel;
    if (values[1] != "") {
        std::stringstream vibrationStream(values[1]);
        if (!(vibrationStream >> vibrationLevel)) {
            return "Vibration level must be a valid number.";
        }
        vibrationStream >> std::ws;
        if (!vibrationStream.eof() || !std::isfinite(vibrationLevel)) {
            return "Vibration level must be a valid number.";
        }
        if (vibrationLevel < 0 || vibrationLevel > 100000) {
            return "Vibration level must be between 0 and 100000.";
        }
    }
    return "";
 }

 std::string Engine::updateValues(std::vector<std::string> values)  {
    if (validateInput(values) != ""){
        return validateInput(values);
    }

    std::stringstream ss1(values[0]);
    double temp = 0;
    ss1 >> temp;
    std::stringstream ss2(values[1]);
    double vibration = 0;
    ss2 >> vibration;

    temperature = temp;
    vibrationLevel = vibration;

    return "";
 }
