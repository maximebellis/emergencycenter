#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "sensor.h"
#include <vector>

enum class SensorSortMethod { ByID, ByVendor, ByVendorThenID, ByLocation, None };

class Customer
{

private:
    int customerId;
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string email;
    std::vector<Sensor*> sensors;

public:
    Customer(int id, const std::string& name, const std::string& address,
             const std::string& phoneNumber, const std::string& email);

    // Getter
    int getCustomerId() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    const std::vector<Sensor*>& getSensors() const;
    void displaySensorsOverview(SensorSortMethod sortMethod = SensorSortMethod::None);


    // Setter
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setPhoneNumber(const std::string& phoneNumber);
    void setEmail(const std::string& email);

    void addSensorComponent(SensorComponent* sensor);
};

#endif // CUSTOMER_H
