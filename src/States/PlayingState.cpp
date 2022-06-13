#include "PlayingState.h"
#include "../Levels/Level.h"

using Levels::Level;

using namespace States;

PlayingState::PlayingState(Level *pl, StateStack *c) :
State(c)
{
    level = pl;
    if(level)
        level->setState(this);
}

PlayingState::~PlayingState()
{
    delete level;
}

void PlayingState::setLevel(Level *l)
{
    level = l;
}

void PlayingState::run(float dt)
{
    if(level)
        level->run(dt);
}

void PlayingState::draw()
{
    if(level)
        level->draw();
}

void PlayingState::reset()
{
    if(level)
        level->reset();
}

void PlayingState::onKeyPressed(Managers::Key k)
{
    if(isOnTop() && level)
        level->onKeyPressed(k);
}

void PlayingState::onKeyReleased(Managers::Key k)
{
    if(isOnTop() && level)
        level->onKeyReleased(k);
}
