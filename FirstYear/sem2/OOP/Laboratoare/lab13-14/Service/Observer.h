#pragma once
#include <vector>

class Observer
{
public:
    /*
     * Updates observer
     */
    virtual void update() = 0;

    /*
     * Virtual destructor
     */
    virtual ~Observer() = default;
};

class Observable
{
private:
    /*
     * observers: list of observers that must be notified
     */
    std::vector<Observer*> observers;

public:
    /*
     * Adds observer
     * :param obs: observer to be added
     */
    void addObserver(Observer* obs)
    {
        observers.push_back(obs);
    }

    /*
     * Removes observer
     * :param obs: observer to be removed
     */
    void removeObserver(Observer* obs)
    {
        for (int i = 0; i < observers.size(); i++)
        {
            if (observers[i] == obs)
            {
                observers.erase(observers.begin() + i);
                return;
            }
        }
    }

protected:
    /*
     * Notifies all observers
     */
    void notify()
    {
        for (Observer* obs : observers)
        {
            obs->update();
        }
    }
};