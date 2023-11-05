#include "sensorgroup.h"
#include <algorithm>
#include <iostream>

// Getters
std::vector<SensorComponent *> SensorGroup::getSensors() const
{
    return sensors;
}

// Specific methods
void SensorGroup::addSensor(SensorComponent* sensor) {
    sensors.push_back(sensor);
}

void SensorGroup::removeSensor(SensorComponent* sensor) {
    sensors.erase(std::remove(sensors.begin(), sensors.end(), sensor), sensors.end());
}

// Overridden methods from SensorComponent interface
void SensorGroup::activate() {
    for (SensorComponent* sensor : sensors) {
        sensor->activate();
    }
}

void SensorGroup::deactivate() {
    for (SensorComponent* sensor : sensors) {
        sensor->deactivate();
    }
}

void SensorGroup::addObserver(Observer* observer) {
    for (SensorComponent* sensor : sensors) {
        sensor->addObserver(observer);
    }
}

void SensorGroup::removeObserver(Observer* observer) {
    for (SensorComponent* sensor : sensors) {
        sensor->removeObserver(observer);
    }
}

void SensorGroup::notifyObservers(const std::string& source) {
    for (SensorComponent* sensor : sensors) {
        sensor->notifyObservers(source);
    }
}


SensorGroup& SensorGroup::operator++() {
    for (SensorComponent* sensor : sensors) {
        sensor->activate();
    }
    return *this;
}

SensorGroup& SensorGroup::operator--() {
    for (SensorComponent* sensor : sensors) {
        sensor->deactivate();
    }
    return *this;
}


