#pragma once

#include <iostream>

class CommandLineController {

    public:
        static void logIdInUse(std::string name);

        static void logNameInUse(std::string id);

        static void logComponentNotFound(std::string id);

        static void logInvalidStatus(std::string status);

        static void logSuccessfulAdd(std::string id, std::string name, std::string type, std::string status);

        static void logSuccessfulUpdate(std::string id, std::string status);

        static void logSuccessfulDelete(std::string id);

        static void logFailedAdd(std::string id, std::string name, std::string type, std::string status);

        static void logFailedUpdate(std::string id, std::string status);

        static void logFailedDelete(std::string id);
};