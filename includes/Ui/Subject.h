#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject {
public:
    void attach(Observer* obs) {
        observers.push_back(obs);
    }

    void detach(Observer* obs) {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void notify() {
        for (Observer* obs : observers) {
            obs->update(this);
        }
    }

private:
    std::vector<Observer*> observers;
};

#endif // SUBJECT_H
