#include <iostream>
#include "EventManager.h"
#include "EventListener.h"

using namespace Managers;

EventManager *EventManager::instance = NULL;

EventManager::EventManager() :
keys(),
listeners()
{}

EventManager::~EventManager()
{
}

EventManager *EventManager::getInstance()
{
    if(!instance) instance = new EventManager();
    return instance;
}

void EventManager::subscribe(EventListener *l)
{
    listeners.push_back(l);
}

void EventManager::unsubscribe(EventListener *l)
{
    listeners.remove(l);
}

void EventManager::onKeyPressed(EventManager::Key k)
{
    keys[k] = true;

    list<EventListener*>::iterator itr = listeners.begin();
    while(itr != listeners.end())
    {
        (*itr)->onKeyPressed(k);
        itr++;
    }
}

void EventManager::onKeyReleased(EventManager::Key k)
{
    keys[k] = false;

    list<EventListener*>::iterator itr;
    for(itr = listeners.begin(); itr != listeners.end(); itr++)
        (*itr)->onKeyReleased(k);
}

bool EventManager::isKeyPressed(EventManager::Key k)
{
    return keys[k];
}
