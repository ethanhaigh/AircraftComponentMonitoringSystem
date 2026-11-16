#pragma once

#include <string>
#include <vector>
#include "../component/ComponentStatus.hpp"

class ComponentMonitor;
class InputParser;

class CommandLineController {
    ComponentMonitor& monitor;
    InputParser& parser;

    public:
        explicit CommandLineController(ComponentMonitor& monitor, InputParser& parser);

        void initialise();

        static void println(std::string str);

        void actionMenu();

        void addComponent();

        void updateComponent();

        void deleteComponent();

        void monitorComponent();

        void displayComponent();

        static void logIdInUse(std::string id);

        static void logNameInUse(std::string name);

        static void logComponentNotFound(std::string id);

        static void logInvalidStatus(std::string status);

        static void logSuccessfulAdd(std::string details);

        static void logSuccessfulUpdate(std::string details);

        static void logSuccessfulDelete(std::string id);

        static void logFailedAdd(std::string id, std::string name, std::string type, std::string status);

        static void logFailedAdd(std::string details);

        static void logFailedUpdate(std::string details);

        static void logFailedDelete(std::string id);

        static void logEmptyId();

        static void logEmptyName();

        static void logEmptyType();

        static void logEmptyStatus();

        static void logDefaultStatus();

        static void logMonitorResult(std::string result);

        static void logInvalidData(std::vector<std::string> dataTypes, std::vector<std::string> parameters, std::string validation);

        static void displayComponent(std::string data);

        static void logComponentNeedsMaintenance(std::string id, std::string name, std::string type, ComponentStatus status);

        static void logComponentHasAlert(std::string id, std::string name, std::string type, std::string status, std::string alert);

        static std::vector<std::string> requestDataForComponent(std::vector<std::string> dataTypes);
};