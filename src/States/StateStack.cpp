#include "StateStack.h"
#include "State.h"
#include <cstdlib>
#include <iostream>

using namespace States;

StateStack::StateStack(State *initialState) :
stateStack(),
pendingList()
{
    initialState->setContext(this);
	stateStack.push_back(initialState);
}

StateStack::~StateStack()
{
    std::vector<State*>::iterator itr = stateStack.begin();

    for( ; itr != stateStack.end(); itr++)
    {
        popState();
    }

    applyPendingChanges();
}

void StateStack::run(float dt)
{
	State *topState = stateStack.back();
	topState->run(dt);

	applyPendingChanges();
}

void StateStack::draw()
{
	State *topState = stateStack.back();
	topState->draw();
}

void StateStack::pushState(State *s)
{
	PendingChange p;
	p.action = Push;
	p.state = s;

	pendingList.push_back(p);
}

void StateStack::popState()
{
    PendingChange p;
	p.action = Pop;
	p.state = NULL;

	pendingList.push_back(p);
}

void StateStack::resetTop()
{
    PendingChange r;

    r.action = Reset;
    r.state = NULL;
    pendingList.push_back(r);
}

void StateStack::applyPendingChanges()
{
	PendingChange c;
	while(!pendingList.empty())
	{
		c = pendingList.front();
		pendingList.pop_front();

		switch(c.action)
		{
			case Pop:
			{
                if(!empty())
                {
                    State *s = stateStack.back();
                    stateStack.pop_back();
                    delete s;
                }
                break;
			}
            case Reset:
                if(!empty())
                {
                    State *s = stateStack.back();
                    s->reset();
                }
                break;
			case Push:
				stateStack.push_back(c.state);
				break;
		}
	}
}

bool StateStack::empty()
{
	return stateStack.empty();
}

const State *StateStack::getTop() const
{
    return stateStack.back();
}
