#include "State.h"
#include "StateStack.h"
#include "../Managers/EventManager.h"

using namespace States;

using Managers::EventManager;

State::State(StateStack *c) :
Ent(),
context(c)
{
    EventManager *em = EventManager::getInstance();
    em->subscribe(this);
}

State::~State() {
    context = NULL;
    EventManager *em = EventManager::getInstance();
    em->unsubscribe(this);
}

void State::requestStackPush(State *s)
{
	context->pushState(s);
}

void State::requestStackPop()
{
	context->popState();
}

void State::requestResetTop()
{
    context->resetTop();
}

StateStack* States::State::getContext() {
    return context;
}

void State::setContext(StateStack *c)
{
    context = c;
}

const bool State::isOnTop() const
{
    return (context->getTop() == this);
}
