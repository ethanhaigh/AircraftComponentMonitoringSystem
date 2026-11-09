#include "Utility.hpp"
#include "../api/CommandLineController.hpp"
#include "ComponentMonitor.hpp"
#include "../component/ComponentStatus.hpp"
#include "InputParser.hpp"
#include <vector>


void InputParser::parseAddInput(std::string input) {
    std::vector<std::string> result = Utility::splitString(input);
    ComponentStatus status;
    if (result[0] == "") {
        CommandLineController::logEmptyId();
        return;
    }
    if (result[1] == "") {
        CommandLineController::logEmptyName();
        return;
    }
    if (result[2] == "") {
        CommandLineController::logDefaultStatus();
        result[2] = "normal";
    } else {
        status = Utility::convertToStatus(result[2]);
        if (status == ComponentStatus::Unknown) {
            return;
        }
    }
    if (result[3] == "") {
        CommandLineController::logEmptyType();
        return;
    }
    monitor.addComponent(result[0], result[1], status, result[3]);

}

void InputParser::parseUpdateInput(std::string input) {
    std::vector<std::string> result = Utility::splitString(input);
    ComponentStatus status;
    if (result[0] == "") {
        CommandLineController::logEmptyId();
        return;
    }
    if (result[1] == "") {
        CommandLineController::logEmptyStatus();
        return;
    } else {
        status = Utility::convertToStatus(result[1]);
        if (status == ComponentStatus::Unknown) {
            return;
        }
    }
    monitor.updateComponent(result[0], status);
}

void InputParser::parseMonitorInput(std::string input)
{
    monitor.monitorComponent(input);
}

void InputParser::parseDeleteInput(std::string input)
{
    monitor.monitorComponent(input);
}

void InputParser::parseDisplayAllInput()
{
    monitor.displayAllComponents();
}

void InputParser::parseDisplayInput(std::string input)
{
    monitor.displayComponent(input);
}

