#ifndef SUBJECT_H
#define SUBJECT_H


#include "observer.h"

class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const std::string& source) = 0;
    virtual ~Subject() = default;
};

#endif // SUBJECT_H
