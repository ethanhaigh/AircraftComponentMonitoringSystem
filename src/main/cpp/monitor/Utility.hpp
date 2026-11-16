#pragma once
#include <iostream>
#include <vector>
#include "../component/ComponentStatus.hpp"

class ComponentMonitor;
class Component;

class Utility {

public:

    static std::string convertToLowercase(std::string input);

    static ComponentStatus convertToStatus(std::string statusName);

    static std::vector<std::string> splitString(std::string input);

    static std::string convertToString(ComponentStatus status);

    static bool isInteger(std::string str);

    static void extractComponents(std::string filePath, ComponentMonitor& monitor);

    static void writeComponents(std::string filePath, std::vector<Component*> components);
};