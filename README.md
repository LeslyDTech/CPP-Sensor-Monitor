# C++ Sensor Monitoring System

A beginner-friendly C++ simulation of an embedded-style sensor monitoring system.

## Overview

This project simulates three sensors:

- Temperature
- Pressure
- Motion

Each sensor generates simulated readings while running on its own thread.

The program uses a state machine to determine whether the overall system is in a:

- NORMAL state
- WARNING state
- CRITICAL state

This project was created to practice C++ object-oriented programming,
multithreading, synchronization, and state-machine concepts.

## Architecture

```text
Temperature Sensor ──┐
                     │
Pressure Sensor ─────┼──> Sensor Data ──> State Machine
                     │                         │
Motion Sensor ───────┘                         ↓
                                      NORMAL / WARNING /
                                          CRITICAL
```

## C++ Concepts Practiced

- Classes and objects
- Constructors
- Encapsulation
- Inheritance
- Polymorphism
- Virtual functions
- Function overriding
- `std::thread`
- `std::mutex`
- `std::lock_guard`
- Enumerations
- State machines
- Random number generation
- Header/source file organization

## Multithreading

Each simulated sensor runs on its own thread.

```text
Thread 1 → Temperature
Thread 2 → Pressure
Thread 3 → Motion
```

Because multiple threads access shared sensor data, a `std::mutex` is
used to protect the data.

## State Machine

The system has three possible states.

### NORMAL

Sensor readings are within expected ranges.

### WARNING

A sensor reaches a warning threshold.

### CRITICAL

A sensor reaches a critical threshold.

## Example Output

```text
=====================================
   C++ Sensor Monitoring System
=====================================

-------------------------------------
Temperature: 72.45 F
Pressure:    14.82 PSI
Motion:      NONE
System State: NORMAL

-------------------------------------
Temperature: 98.32 F
Pressure:    15.61 PSI
Motion:      DETECTED
System State: WARNING
WARNING: Sensor threshold exceeded!

-------------------------------------
Temperature: 107.25 F
Pressure:    15.93 PSI
Motion:      DETECTED
System State: CRITICAL
ALERT: Critical sensor condition!
```

## How to Compile

Using g++:

```bash
g++ -std=c++17 main.cpp Sensor.cpp StateMachine.cpp -pthread -o sensor_monitor
```

## How to Run

Linux/macOS:

```bash
./sensor_monitor
```

Windows:

```bash
sensor_monitor.exe
```

## Future Improvements

Possible future improvements include:

- Real Arduino sensor input
- Logging sensor readings to a file
- Configurable sensor thresholds
- Additional sensor types
- Hardware integration
- Unit tests
- More advanced state transitions

## What I Learned

This project helped me practice organizing a C++ program across
multiple source and header files.

I also learned how inheritance and polymorphism can be used to represent
different types of sensors while sharing a common interface.

The multithreading portion helped me understand why shared data needs
synchronization when multiple threads access it at the same time.
