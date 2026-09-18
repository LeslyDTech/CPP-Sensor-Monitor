#ifndef SENSOR_H
#define SENSOR_H

#include <string>

// Base class for all sensors
class Sensor {
protected:
    std::string name;
    double value;

public:
    Sensor(const std::string& sensorName);
    virtual ~Sensor() = default;

    // Each sensor implements its own way of generating data
    virtual void update() = 0;

    std::string getName() const;
    double getValue() const;
};

// Temperature sensor
class TemperatureSensor : public Sensor {
public:
    TemperatureSensor();
    void update() override;
};

// Pressure sensor
class PressureSensor : public Sensor {
public:
    PressureSensor();
    void update() override;
};

// Motion sensor
class MotionSensor : public Sensor {
public:
    MotionSensor();
    void update() override;
};

#endif
