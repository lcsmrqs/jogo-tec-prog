#include <iostream>
#include "MenuState.h"

using namespace States;

MenuState::MenuState(Menu *m, StateStack *c) :
State(c),
menu(m)
{
    menu->setState(this);
}

MenuState::~MenuState()
{
    delete menu;
}

void MenuState::setMenu(Menu *m)
{
    menu = m;
}

void MenuState::run(float dt)
{
    if(menu)
        menu->run(dt);
}

void MenuState::draw()
{
    if(menu)
        menu->draw();
}

void MenuState::reset()
{
    menu->reset();
}

void MenuState::onKeyPressed(Managers::Key k)
{
    if(isOnTop())
        menu->onKeyPressed(k);
}

void MenuState::onKeyReleased(Managers::Key k)
{
    if(isOnTop())
        menu->onKeyReleased(k);
}
