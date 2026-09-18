#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <string>

enum class SystemState {
    NORMAL,
    WARNING,
    CRITICAL
};

class StateMachine {
private:
    SystemState currentState;

public:
    StateMachine();

    void updateState(
        double temperature,
        double pressure,
        double motion
    );

    SystemState getState() const;
    std::string getStateName() const;
};

#endif
