#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <iomanip>

#include "Sensor.h"
#include "StateMachine.h"

// Protects shared sensor data
std::mutex sensorMutex;

// Function that updates a sensor repeatedly
void runSensor(Sensor& sensor) {
    for (int i = 0; i < 10; i++) {
        {
            // Lock shared data while updating it
            std::lock_guard<std::mutex> lock(sensorMutex);
            sensor.update();
        }

        // Wait one second before the next reading
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::cout << "=====================================\n";
    std::cout << "   C++ Sensor Monitoring System\n";
    std::cout << "=====================================\n\n";

    // Create our sensors
    TemperatureSensor temperatureSensor;
    PressureSensor pressureSensor;
    MotionSensor motionSensor;

    // Create the state machine
    StateMachine stateMachine;

    // Create a thread for each sensor
    std::thread temperatureThread(
        runSensor,
        std::ref(temperatureSensor)
    );

    std::thread pressureThread(
        runSensor,
        std::ref(pressureSensor)
    );

    std::thread motionThread(
        runSensor,
        std::ref(motionSensor)
    );

    // Main monitoring loop
    for (int i = 0; i < 10; i++) {
        double temperature;
        double pressure;
        double motion;

        {
            // Protect shared sensor data
            std::lock_guard<std::mutex> lock(sensorMutex);

            temperature = temperatureSensor.getValue();
            pressure = pressureSensor.getValue();
            motion = motionSensor.getValue();
        }

        // Update the system state
        stateMachine.updateState(
            temperature,
            pressure,
            motion
        );

        // Display sensor information
        std::cout << "\n-------------------------------------\n";
        std::cout << std::fixed << std::setprecision(2);

        std::cout << "Temperature: "
                  << temperature
                  << " F\n";

        std::cout << "Pressure:    "
                  << pressure
                  << " PSI\n";

        std::cout << "Motion:      "
                  << (motion == 1 ? "DETECTED" : "NONE")
                  << "\n";

        std::cout << "System State: "
                  << stateMachine.getStateName()
                  << "\n";

        // Display alerts
        if (stateMachine.getState() == SystemState::WARNING) {
            std::cout << "WARNING: Sensor threshold exceeded!\n";
        }
        else if (stateMachine.getState() == SystemState::CRITICAL) {
            std::cout << "ALERT: Critical sensor condition!\n";
        }

        // Wait before checking again
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Wait for all sensor threads to finish
    temperatureThread.join();
    pressureThread.join();
    motionThread.join();

    std::cout << "\n=====================================\n";
    std::cout << "Monitoring complete.\n";
    std::cout << "=====================================\n";

    return 0;
}
