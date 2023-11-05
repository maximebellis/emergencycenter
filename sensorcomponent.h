#ifndef SENSORCOMPONENT_H
#define SENSORCOMPONENT_H

#include <memory>
#include "subject.h"
#include "subject.h"

enum class SensorType { SMOKE, MOTION, GAS };

inline std::string sensorTypeToString(SensorType type) {
    switch(type) {
    case SensorType::SMOKE: return "Smoke";
    case SensorType::MOTION: return "Motion";
    case SensorType::GAS: return "Gas";
    default: return "UNKNOWN";
    }
}

class SensorComponent: public Subject{
public:

    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const std::string& source) = 0;

    virtual SensorComponent& operator++() = 0;
    virtual SensorComponent& operator--() = 0;


    // Destructor
    virtual ~SensorComponent() = default;
};


#endif // SENSORCOMPONENT_H
