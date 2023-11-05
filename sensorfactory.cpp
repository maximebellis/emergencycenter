#include "sensorfactory.h"

Sensor* SensorFactory::createSensor(const std::string& vendor, const std::string& location, SensorType type) {
    return new Sensor(vendor, location, type);
}

