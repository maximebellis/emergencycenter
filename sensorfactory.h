#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include "sensor.h"
#include <string>

class SensorFactory {
public:
    static Sensor* createSensor(const std::string& vendor, const std::string& location, SensorType type);

};

#endif // SENSORFACTORY_H
