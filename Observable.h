#ifndef PROGETTO_PROGRESSBAR_OBSERVABLE_H
#define PROGETTO_PROGRESSBAR_OBSERVABLE_H

#include <vector>
#include "Observer.h"

//classe che sara' osservata dagli observer e quindi dalla progress bar

class Observable {
private:
    std::vector<Observer*> observers;
public:
    virtual ~Observable() = default;

    virtual void addObserver(Observer* obs){
        observers.push_back(obs);
    };
    virtual void notifyObserver(float progress) {
        for (Observer* obs : observers){
            obs->updateProgress(progress);
        }
    }
};

#endif