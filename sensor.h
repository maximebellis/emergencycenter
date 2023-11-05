#ifndef SENSOR_H
#define SENSOR_H

#include "sensorcomponent.h"
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "action.h"
#include <chrono>
#include "messages.h"


class Sensor : public SensorComponent {
private:
    int id;
    static int nextId;
    std::string vendor;
    std::string location;
    bool isActive;
    SensorType sensorType;
    std::vector<const Action*> actions;
    std::vector<Observer*> observers;
    std::chrono::hours activeStartHour;
    std::chrono::hours activeEndHour;
    bool useActiveHours = false;
    bool working = true;
    bool isWithinActiveHours() const;
    bool isWithinActivationRange(double value) const;
    double activationRange;


public:

    //Constructor
    Sensor(const std::string& vendor, const std::string& location, SensorType type);

    // Getters
    SensorType getSensorType() const;
    bool isWorking() const;
    int getId() const;
    bool isActivated() const;
    std::string getVendor() const;
    std::string getLocation() const;

    // Specific methods
    void addAction(const Action* action);

    void receiveMessage(MessageType type);
    void handleTestRequest();
    void setActiveHours(int startHour, int endHour);
    void setActivationRange(double range);


    // Overridden methods from SensorComponent interface
    void activate() override;
    void deactivate() override;
    void addObserver(Observer* observer) override;
    void removeObserver(Observer* observer) override;
    void notifyObservers(const std::string& source) override;


    Sensor& operator++() override;
    Sensor& operator--() override;


    // Destructor
    ~Sensor() override = default;
};

std::ostream& operator<<(std::ostream& os, const Sensor& sensor);


#endif // SENSOR_H
