#include "customer.h"
#include "sensor.h"
#include "sensorgroup.h"
#include "sensorcomponent.h"
#include <algorithm>
#include <iostream>


bool compareById(Sensor* a, Sensor* b) {
    return a->getId() < b->getId();
}

bool compareByVendor(Sensor* a, Sensor* b) {
    return a->getVendor() < b->getVendor();
}

bool compareByVendorThenID(Sensor* a, Sensor* b) {
    if (a->getVendor() == b->getVendor()) {
        return a->getId() < b->getId();
    }
    return a->getVendor() < b->getVendor();
}


// Constructor
Customer::Customer(int id, const std::string& name, const std::string& address,
                   const std::string& phoneNumber, const std::string& email)
    : customerId(id), name(name), address(address), phoneNumber(phoneNumber), email(email) {}

// Getters
int Customer::getCustomerId() const {
    return customerId;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getAddress() const {
    return address;
}

std::string Customer::getPhoneNumber() const {
    return phoneNumber;
}

std::string Customer::getEmail() const {
    return email;
}

const std::vector<Sensor*>& Customer::getSensors() const
{
    return sensors;
}

// Setters
void Customer::setName(const std::string& newName) {
    name = newName;
}

void Customer::setAddress(const std::string& newAddress) {
    address = newAddress;
}

void Customer::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Customer::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void Customer::addSensorComponent(SensorComponent* sensorComponent)
{
    Sensor* sensor = dynamic_cast<Sensor*>(sensorComponent);
    if (sensor) {
        sensors.push_back(sensor);
        return;
    }

    SensorGroup* group = dynamic_cast<SensorGroup*>(sensorComponent);
    if (group) {
        const auto& groupSensors = group->getSensors();
        for (SensorComponent* groupSensorComponent : groupSensors) {
            addSensorComponent(groupSensorComponent);
        }
    }
}



void Customer::displaySensorsOverview(SensorSortMethod sortMethod) {
    auto compareFunc = [&sortMethod](Sensor* a, Sensor* b) {
        switch (sortMethod) {
        case SensorSortMethod::ByID:
            return a->getId() < b->getId();
        case SensorSortMethod::ByLocation:
            return a->getLocation() < b->getLocation();
        case SensorSortMethod::ByVendor:
            return a->getVendor() < b->getVendor();
        case SensorSortMethod::ByVendorThenID:
            if (a->getVendor() == b->getVendor()) {
                return a->getId() < b->getId();
            }
            return a->getVendor() < b->getVendor();
        case SensorSortMethod::None:
            return false;
        }
    };

    std::sort(sensors.begin(), sensors.end(), compareFunc);

    for (Sensor* sensor : sensors) {
        std::cout << *sensor << std::endl;
    }
}

