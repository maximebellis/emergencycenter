#ifndef SENSORGROUP_H
#define SENSORGROUP_H

#include "sensorcomponent.h"
#include <vector>
#include <memory>
#include <string>

class SensorGroup : public SensorComponent{
private:
    std::vector<SensorComponent*> sensors;


public:

    // Getters
    std::vector<SensorComponent *> getSensors() const;

    // Specific methods
    void addSensor(SensorComponent* sensor);
    void removeSensor(SensorComponent* sensor);



    // Overridden methods from SensorComponent interface
    void activate() override;
    void deactivate() override;
    void addObserver(Observer* observer) override;
    void removeObserver(Observer* observer) override;
    void notifyObservers(const std::string& source) override;

    SensorGroup& operator++() override;
    SensorGroup& operator--() override;

    // Destructor
    ~SensorGroup() override = default;

};

#endif // SENSORGROUP_H
