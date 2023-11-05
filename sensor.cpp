#include "sensor.h"
#include <iostream>

// Constructor

int Sensor::nextId = 1;

Sensor::Sensor(const std::string& vendor, const std::string& location, SensorType type)
    : id(nextId++), vendor(vendor), location(location), sensorType(type) {}

// Getters
SensorType Sensor::getSensorType() const {
    return sensorType;
}

int Sensor::getId() const {
    return id;
}

std::string Sensor::getLocation() const {
    return location;
}

bool Sensor::isActivated() const {
    return isActive;
}

bool Sensor::isWorking() const {
    return working;
}

std::string Sensor::getVendor() const
{
    return vendor;
}




// Specific methods
void Sensor::addAction(const Action* action) {
    actions.push_back(action);
}

bool Sensor::isWithinActiveHours() const {
    if(!useActiveHours) return true;
    auto now = std::chrono::system_clock::now();
    std::time_t nowTimeT = std::chrono::system_clock::to_time_t(now);
    std::tm nowTm = *std::localtime(&nowTimeT);
    std::chrono::hours currentHour(nowTm.tm_hour);
    if (activeEndHour <= activeStartHour) {
        return (currentHour >= activeStartHour || currentHour < activeEndHour);
    }
    return (currentHour >= activeStartHour && currentHour < activeEndHour);
}

bool Sensor::isWithinActivationRange(double value) const {
    return (value >= 0.0 && value <= activationRange);
}

void Sensor::setActiveHours(int startHour, int endHour) {
    activeStartHour = std::chrono::hours(startHour);
    activeEndHour = std::chrono::hours(endHour);
    useActiveHours = true;
}

void Sensor::receiveMessage(MessageType type) {
    switch(type) {
    case MessageType::TEST_REQUEST:
        handleTestRequest();
        break;
    }
}

void Sensor::handleTestRequest() {
    working = true;
    notifyObservers("test");
}

std::ostream& operator<<(std::ostream& os, const Sensor& sensor) {
    os << sensorTypeToString(sensor.getSensorType()) << " sensor (id: " << sensor.getId() << ") from "
       << sensor.getVendor() << " at " << sensor.getLocation() << ". "
       << "Status: " << (sensor.isActivated() ? "ON" : "OFF");
    return os;
}

// Add a setter function to set the activation range
void Sensor::setActivationRange(double range) {
    activationRange = range;
}




// Overridden methods from SensorComponent interface
void Sensor::activate() {
    if (isActive) {
        std::cout << "Sensor | Attempted to activate the sensor (id: " << id << "), but it's already on." << std::endl;
        return;
    }
    if(isWithinActiveHours()) {
        isActive = true;
        notifyObservers("activate");
        for (const auto& action : actions) {
            action->execute();
        }
    }
    else {
        std::cout << "Sensor | Sensor (id: " << id << ") activation request outside active hours." << std::endl;
    }
}

void Sensor::deactivate() {
    if (!isActive) {
        std::cout << "Sensor | Attempted to deactivate the sensor (id: " << id << "), but it's already off." << std::endl;
        return;
    }
    isActive = false;
    notifyObservers("deactivate");
}


void Sensor::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Sensor::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Sensor::notifyObservers(const std::string& source) {
    for (Observer* observer : observers) {
        observer->update(this, source);
    }
}


Sensor& Sensor::operator++() {
    this->activate();
    return *this;
}

Sensor& Sensor::operator--() {
    this->deactivate();
    return *this;
}




