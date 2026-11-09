#pragma once
#include <iostream>
#include <vector>
#include "ComponentMonitor.hpp"

class InputParser {

private:
    ComponentMonitor monitor;

public:
    void parseAddInput(std::string input);
    void parseUpdateInput(std::string input);
    void parseDeleteInput(std::string input);
    void parseMonitorInput(std::string input);
    void parseDisplayAllInput();
    void parseDisplayInput(std::string input);
};