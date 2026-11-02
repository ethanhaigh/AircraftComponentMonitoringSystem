#pragma once

#include <iostream>

class CommandLineController {

    public:
        static void logIdInUse(std::string name);

        static void logNameInUse(std::string id);

        static void logComponentNotFound(std::string id);
}