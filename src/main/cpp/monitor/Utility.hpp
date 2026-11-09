#pragma once
#include <iostream>
#include <vector>
#include "../component/ComponentStatus.hpp"


class Utility {

public:

    static std::string convertToLowercase(std::string input);

    static ComponentStatus convertToStatus(std::string statusName);

    static std::vector<std::string> splitString(std::string input);

    static std::string convertToString(ComponentStatus status);
};