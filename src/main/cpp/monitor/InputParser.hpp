#pragma once
#include <string>
#include <vector>

class ComponentMonitor;

class InputParser {

private:
    ComponentMonitor& monitor;

public:
    explicit InputParser(ComponentMonitor& monitor);

    bool parseAddInput(std::string input);
    bool parseUpdateInput(std::string input);
    void parseDeleteInput(std::string input);
    void parseMonitorInput(std::string input);
    void parseDisplayAllInput();
    void parseDisplayInput(std::string input);
};