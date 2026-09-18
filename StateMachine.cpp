#include "StateMachine.h"

StateMachine::StateMachine()
    : currentState(SystemState::NORMAL) {
}

void StateMachine::updateState(
    double temperature,
    double pressure,
    double motion,
    double battery
) {
    // Critical condition
    if (temperature >= 105.0 || pressure >= 15.8) {
        currentState = SystemState::CRITICAL;
    }

    // Warning condition
    else if (temperature >= 95.0 ||
             pressure >= 15.5 ||
             motion == 1    ||
             battery <= 20.0) {
        currentState = SystemState::WARNING;
    }

    // Everything is normal
    else {
        currentState = SystemState::NORMAL;
    }
}

SystemState StateMachine::getState() const {
    return currentState;
}

std::string StateMachine::getStateName() const {
    switch (currentState) {
        case SystemState::NORMAL:
            return "NORMAL";

        case SystemState::WARNING:
            return "WARNING";

        case SystemState::CRITICAL:
            return "CRITICAL";
    }

    return "UNKNOWN";
}
