#pragma once
#include <iostream>
#include "../component/ComponentStatus.hpp"


class Utility {

public:

    static std::string convertToLowercase(std::string input);

    static ComponentStatus convertToStatus(std::string statusName);
};