#include <iostream>
#include "../component/ComponentStatus.hpp"
#include "../api/CommandLineController.hpp"
#include <cctype>
#include "Utility.hpp"

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
    }
}