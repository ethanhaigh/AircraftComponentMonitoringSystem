#include "CommandLineController.hpp"
#include <iostream>
#include <string>
#include "../monitor/Utility.hpp"
#include "../monitor/ComponentMonitor.hpp"
#include "../monitor/InputParser.hpp"
#include "../component/ComponentStatus.hpp"

CommandLineController::CommandLineController(ComponentMonitor& monitor, InputParser& parser)
    : monitor(monitor), parser(parser) {}

void CommandLineController::initialise()
{
    println(" ---------------------------------------------------------------- ");
    println("|              AIRCRAFT COMPONENT MONITORING SYSTEM              |");
    println(" ---------------------------------------------------------------- ");
    println("");
    actionMenu();
}

void CommandLineController::println(std::string str)
{
    std::cout << str + "\n";
}

void CommandLineController::actionMenu()
{
    while (true) {
        println(" ---------------------------------------------------------------- ");
        println("");
        println("What would you like to do?");
        println("1. Add Component");
        println("2. Delete Component");
        println("3. Update Component");
        println("4. Monitor Component");
        println("5. Get Component Details");
        println("6. Get All Component Details");
        println("7. Exit");
        println("");
        println("Please return a number.");
        println("");

        std::string response;
        std::cin >> response;

        if (!Utility::isInteger(response)) {
            println("Input is invalid. Please enter a number");
            continue;
        }

        int num = std::stoi(response);

        if (num == 1) {
            addComponent();
        } else if (num == 2) {
            deleteComponent();
        } else if (num == 3) {
            updateComponent();
        } else if (num == 4) {
            monitorComponent();
        } else if (num == 5) {
            displayComponent();
        } else if (num == 6) {
            parser.parseDisplayAllInput();
        } else if (num == 7) {
            monitor.quit();
            return;
        } else {
            println("Input is invalid. Please enter a specified number");
            continue;
        }
    }
}

void CommandLineController::addComponent() 
{
    println("");
    println("Please specify a component ID");
    std::string id;
    std::cin >> id;
    println("");
    println("Please specify a component name");
    std::string name;
    std::cin >> name;
    println("");
    println("Please specify a component status from the following options:");
    println("Normal");
    println("Warning");
    println("Fault");
    std::string status;
    std::cin >> status;
    println("");
    println("Please specify a component type from the following options:");
    for (std::string type : monitor.getTypes())
    {
        println(type);
    }
    std::string type;
    std::cin >> type;
    println("");

    std::string out = id + "," + name + "," + status + "," + type;
    parser.parseAddInput(out);
};

void CommandLineController::updateComponent()
{
    println("");
    println("Please specify a component ID");
    std::string id;
    std::cin >> id;
    println("");
    println("Please specify a component status from the following options:");
    println("Normal");
    println("Warning");
    println("Fault");
    std::string status;
    std::cin >> status;
    println("");

    std::string out = id + "," + status;
    parser.parseUpdateInput(out);
}

void CommandLineController::deleteComponent()
{
    println("");
    println("Please specify a component ID");
    std::string id;
    std::cin >> id;
    println("");

    parser.parseDeleteInput(id);
}

void CommandLineController::monitorComponent()
{
    println("");
    println("Please specify a component ID");
    std::string id;
    std::cin >> id;
    println("");

    parser.parseMonitorInput(id);
}

void CommandLineController::displayComponent()
{
    println("");
    println("Please specify a component ID");
    std::string id;
    std::cin >> id;
    println("");

    parser.parseDisplayInput(id);
}

void CommandLineController::logIdInUse(std::string id)         
{
    println("");
    println("ERROR: Component Id: '" + id + "' is already in use.");
}   

void CommandLineController::logNameInUse(std::string name)
{
    println("");
    println("ERROR: Component Name: '" + name + "' is already in use.");
}   

void CommandLineController::logComponentNotFound(std::string id)
{
    println("");
    println("ERROR: No component exists with Id: '" + id + "'.");
}  

void CommandLineController::logInvalidStatus(std::string status)
{
    println("");
    println("ERROR: No valid status exists with name: '" + status + "'.");
}

void CommandLineController::logSuccessfulAdd(std::string details)
{
    println("");
    println("Successfully added component!");
    println(details);
    println("");
}  

void CommandLineController::logSuccessfulUpdate(std::string details)
{
    println("");
    println("Successfully updated component!");
    println(details);
    println("");
}  

void CommandLineController::logSuccessfulDelete(std::string id)
{
    println("");
    println("Successfully deleted component!");
    println("ComponentId: " + id);
    println("");
}  

void CommandLineController::logFailedAdd(std::string details)
{
    println("");
    println("ERROR: Failed to add component");
    println(details);
    println("");
}  

void CommandLineController::logFailedAdd(std::string id, std::string name, std::string type, std::string status)
{
    println("");
    println("ERROR: Failed to add component");
    println("ComponentId: " + id);
    println("Name       : " + name);
    println("Status     : " + status);
    println("Type       : " + type);
    println("");
} 

void CommandLineController::logFailedUpdate(std::string details)
{
    println("");
    println("ERROR: Failed to update component.");
    println(details);
    println("");
}  

void CommandLineController::logFailedDelete(std::string id)
{
    println("");
    println("ERROR: Failed to delete component.");
    println("ComponentId: " + id);
    println("");
}   

void CommandLineController::logEmptyId()
{
    println("");
    println("ERROR: Provided ComponentId has no value");
}   

void CommandLineController::logEmptyName()
{
    println("");
    println("ERROR: Provided name has no value");
}   

void CommandLineController::logEmptyType()
{
    println("");
    println("ERROR: Provided type has no value");
}  

void CommandLineController::logEmptyStatus()
{
    println("");
    println("ERROR: Provided status has no value");
}    

void CommandLineController::logDefaultStatus()
{
    println("");
    println("No status has been provided, 'Default' status has been used.");
}     

void CommandLineController::logMonitorResult(std::string result)
{
    println("MONITORING RESULT: " + result);
}       

void CommandLineController::logInvalidData(std::vector<std::string> dataTypes, std::vector<std::string> parameters, std::string validation)
{
    println("");
    println("ERROR: The data entered is invalid.");
    println(validation);
}

void CommandLineController::displayComponent(std::string data)
{
    println("");
    println("Display Component");
    println(data);
    println("");
}        

void CommandLineController::logComponentNeedsMaintenance(std::string id, std::string name, std::string type, ComponentStatus status)
{
    println("");
    println("The following component REQUIRES MAINTENANCE due to STATUS being " + Utility::convertToString(status));
    println("ComponentId: " + id);   
    println("Name       : " + name); 
    println("Type       : " + type); 
    println("");
}       

void CommandLineController::logComponentHasAlert(std::string id, std::string name, std::string type, std::string status, std::string alert)
{
    println("");
    println("The following component has an ALERT:");
    println("ComponentId: " + id);   
    println("Name       : " + name); 
    println("Type       : " + type); 
    println("Status     : " + status); 
    println("Alert      : " + alert); 
    println("");
}

std::vector<std::string> CommandLineController::requestDataForComponent(std::vector<std::string> dataTypes)
{
    std::vector<std::string> out;
    println("");
    println("Empty fields will keep the component's data unchanged.");
    for (std::string type : dataTypes)
    {
        println("Please specify the following data: " + type);
        std::string response;
        std::cin >> response;
        out.push_back(response);
        println("");
    }
    return out;
}