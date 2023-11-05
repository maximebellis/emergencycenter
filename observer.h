#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

//this is the observer interface

class Observer {
public:
    virtual void update() = 0;
    virtual void update(void* sender, const std::string& source) = 0;
    virtual ~Observer() = default;
};

#endif // OBSERVER_H
