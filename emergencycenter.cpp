#include "emergencycenter.h"
#include "sensor.h"
#include "sensorgroup.h"
#include <algorithm>
#include <iostream>
#include <sstream>


void emergencycenter::update() {
    // Handle notifications from sensors
}

void emergencycenter::update(void* sender, const std::string& sourceAction) {
    Sensor* sensor = static_cast<Sensor*>(sender);
    std::stringstream ss;
    ss << "Center | Sensor (id: " << sensor->getId() << ") ";

    if (sourceAction == "activate") {
        ss << "has been activated.";
    } else if (sourceAction == "deactivate") {
        ss << "has been deactivated.";
    } else if (sourceAction == "test") {
        if (sensor->isWorking()) {
            sensor->activate();
            ss << "passed the test and is functioning properly.";
        } else {
            ss << "failed the test and has encountered an issue.";
        }
    } else {
        ss << "received an unknown action.";
    }

    std::cout << ss.str() << std::endl;
}


void emergencycenter::testSensorComponent(SensorComponent* sensorComponent) {
    Sensor* sensor = dynamic_cast<Sensor*>(sensorComponent);
    if (sensor) {
        sensor->receiveMessage(MessageType::TEST_REQUEST);
        return;
    }

    SensorGroup* sensorGroup = dynamic_cast<SensorGroup*>(sensorComponent);
    if (sensorGroup) {
        const auto& groupSensors = sensorGroup->getSensors();
        for (SensorComponent* innerSensorComponent : groupSensors) {
            Sensor* groupSensor = dynamic_cast<Sensor*>(innerSensorComponent);
            if (groupSensor) {
                groupSensor->receiveMessage(MessageType::TEST_REQUEST);
            }
        }
    }
}



void emergencycenter::registerCustomer(Customer* customer) {
    registeredCustomers.push_back(customer);
    const auto& customerSensors = customer->getSensors();

    for (Sensor* sensor : customerSensors) {
        sensor->addObserver(this);
    }
}


