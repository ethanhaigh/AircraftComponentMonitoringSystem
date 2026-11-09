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

        static void logEmptyId();

        static void logEmptyName();

        static void logEmptyType();

        static void logEmptyStatus();

        static void logDefaultStatus();

        static void logMonitorResult(std::string result);

        static void logInvalidData(std::vector<std::string> dataTypes, std::vector<std::string> parameters, std::string validation);

        static void displayComponent(std::string data);

        static std::vector<std::string> requestDataForComponent(std::vector<std::string> dataTypes);
};