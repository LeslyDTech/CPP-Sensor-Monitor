#include "Sensor.h"

#include <random>

// Base Sensor constructor
Sensor::Sensor(const std::string& sensorName)
    : name(sensorName), value(0.0) {
}

std::string Sensor::getName() const {
    return name;
}

double Sensor::getValue() const {
    return value;
}

// Temperature Sensor
TemperatureSensor::TemperatureSensor()
    : Sensor("Temperature") {
}

void TemperatureSensor::update() {
    static std::random_device rd;
    static std::mt19937 generator(rd());

    // Generate a temperature between 65 and 110 degrees
    std::uniform_real_distribution<double> distribution(65.0, 110.0);
    value = distribution(generator);
}

// Pressure Sensor
PressureSensor::PressureSensor()
    : Sensor("Pressure") {
}

void PressureSensor::update() {
    static std::random_device rd;
    static std::mt19937 generator(rd());

    // Generate pressure between 14 and 16 PSI
    std::uniform_real_distribution<double> distribution(14.0, 16.0);
    value = distribution(generator);
}

// Motion Sensor
MotionSensor::MotionSensor()
    : Sensor("Motion") {
}

void MotionSensor::update() {
    static std::random_device rd;
    static std::mt19937 generator(rd());

    // Generate either 0 or 1
    std::uniform_int_distribution<int> distribution(0, 1);
    value = distribution(generator);
}

// Battery Sensor
BatterySensor::BatterySensor()
    : Sensor("Battery") {
}

void BatterySensor::update() {
    static std::random_device rd;
    static std::mt19937 generator(rd());

    // Generate battery level between 10 and 100 percent
    std::uniform_real_distribution<double> distribution(10.0, 100.0);
    value = distribution(generator);
}
