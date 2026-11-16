#include <iostream>
#include <fstream>
#include "../component/ComponentStatus.hpp"
#include "../api/CommandLineController.hpp"
#include <cctype>
#include <vector>
#include <sstream>
#include <optional>
#include "Utility.hpp"
#include "ComponentMonitor.hpp"
#include "../component/Component.hpp"
#include <algorithm>

std::string Utility::convertToLowercase(std::string input) {
    std::string output = "";

    for (int i = 0; i < input.length(); i++)
    {
        output = output  + (char)tolower(input[i]);
    }

    return output;
}

ComponentStatus Utility::convertToStatus(std::string statusName) {
    if (convertToLowercase(statusName) == "normal")
    {
        return ComponentStatus::Normal;
    }
    else if (convertToLowercase(statusName) == "warning")
    {
        return ComponentStatus::Warning;
    }
    else if (convertToLowercase(statusName) == "fault")
    {
        return ComponentStatus::Fault;
    }
    else
    {
        CommandLineController::logInvalidStatus(statusName);
        return ComponentStatus::Unknown;
    }
}

std::string Utility::convertToString(ComponentStatus status)
{
    switch (status)
    {
        case ComponentStatus::Normal:
            return "Normal";

        case ComponentStatus::Warning:
            return "Warning";

        case ComponentStatus::Fault:
            return "Fault";

        case ComponentStatus::Unknown:
            return "Unknown";
    }
    return "Unknown";
}

std::vector<std::string> Utility::splitString(std::string input) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string item;
    while (std::getline(ss, item, ','))
    {
        result.push_back(item);
    }
    return result;
}

bool Utility::isInteger(std::string str) {
    if (str.empty()) return false;
    
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

void Utility::extractComponents(std::string filePath, ComponentMonitor& monitor) {
    
    std::ifstream fin(filePath);

    if (!fin.is_open())
    {
        std::cout << "ERROR: Could not open file: " << filePath << std::endl;
        return;
    }

    std::vector<std::string> componentData;

    std::string line, word;

    while (std::getline(fin, line))
    {
        if (line.empty())
            continue;

        componentData.clear();

        std::stringstream s(line);

        while (getline(s, word, ','))
        {
            componentData.push_back(word);
        }

        if (componentData.size() < 4)
        {
            std::cout << "ERROR: Invalid component data in CSV." << std::endl;
            continue;
        }

        std::vector<std::string> parameters;

        for (int i = 4; i < componentData.size(); i++)
        {
            parameters.push_back(componentData[i]);
        }
        Component* component = monitor.addExistingComponent(componentData[0], componentData[1], convertToStatus(componentData[2]), componentData[3]);

        if (component != nullptr)
        {
            component->updateValues(parameters);
        }
    }

    fin.close();

}

void Utility::writeComponents(std::string filePath, std::vector<Component*> components) {

    std::ofstream fout;

    fout.open(filePath, std::ios::out | std::ios::app);

    std::string fileContents = "";

    for (Component* component : components) {
        std::string data = "";
        data = data + component->getId() + ",";
        data = data + component->getName() + ",";
        data = data + convertToString(component->getStatus()) + ",";
        data = data + component->getType() + ",";
        data = data + component->getData();
        data = data + "\n";

        fileContents = fileContents + data;
    }

    fout << fileContents;
}