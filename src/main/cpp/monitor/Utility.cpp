#include <iostream>
#include "../component/ComponentStatus.hpp"
#include "../api/CommandLineController.hpp"
#include <cctype>
#include <vector>
#include <sstream>
#include <optional>
#include "Utility.hpp"
#include "ComponentMonitor.hpp"
#include "../component/Component.hpp"

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