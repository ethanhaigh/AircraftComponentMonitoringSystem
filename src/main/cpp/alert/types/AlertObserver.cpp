#include "AlertObserver.hpp"
#include "../../component/Component.hpp"
#include "../../api/CommandLineController.hpp"
#include "../../monitor/Utility.hpp"

AlertObserver::AlertObserver()
{
}

std::string AlertObserver::getType() const {
    return "alert";
}

void AlertObserver::notify(Component* component, std::string reason) const {
    if (reason.rfind("WARNING", 0) == 0) {
    //std::vector<std::string> result = Utility::splitString(reason);
    CommandLineController::logComponentHasAlert(component->getId(), component->getName(), component->getType(), Utility::convertToString(component->getStatus()), reason);
    }
}