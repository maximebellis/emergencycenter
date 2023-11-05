#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H

#include <vector>
#include "observer.h"
#include "customer.h"
#include <algorithm>
#include <vector>
#include "sensor.h"
#include "observer.h"
#include <algorithm>


class emergencycenter : public Observer{
private:
    std::vector<Customer*> registeredCustomers;
    std::vector<Observer*> observers;
    Sensor* findSensorByID(int sensorID);


public:

    virtual ~emergencycenter() = default;

    void registerCustomer(Customer* customer);
    void testSensorComponent(SensorComponent* sensorComponent);

    void update() override;
    void update(void* sender, const std::string& source) override;

};

#endif // EMERGENCYCENTER_H
