#include <iostream>
#include "EventManager.h"
using namespace Managers;

EventManager *EventManager::instance = NULL;

EventManager::EventManager() :
keys()
{}

EventManager::~EventManager()
{
}

EventManager *EventManager::getInstance()
{
    if(!instance) instance = new EventManager();
    return instance;
}

void EventManager::keyPressed(EventManager::Key k) {
    keys[k] = true;
}

void EventManager::keyReleased(EventManager::Key k) {
    keys[k] = false;
}

bool EventManager::isKeyPressed(EventManager::Key k) {
    return keys[k];
}
