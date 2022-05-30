#include "Saci.h"
#include "../../Managers/EventManager.h"

using Managers::EventManager;
using Key = EventManager::Key;

#include <iostream>

#define SPEED 150.0f

using namespace Entities::Characters;

Saci::Saci() :
Player()
{
    sprite.setFillColor(sf::Color::Red);
}

Saci::Saci(Vect pos, Vect vel) :
Player(pos, vel)
{
    sprite.setFillColor(sf::Color::Red);
}

Saci::~Saci() {}

void Saci::run(float dt)
{
    EventManager *em = EventManager::getInstance();

    if(em->isKeyPressed(Key::Up))
        velocity.setY(velocity.getY() - SPEED);
    if(em->isKeyPressed(Key::Down))
        velocity.setY(velocity.getY() + SPEED);
    if(em->isKeyPressed(Key::Right))
        velocity.setX(velocity.getX() + SPEED);
    if(em->isKeyPressed(Key::Left))
        velocity.setX(velocity.getX() - SPEED);

    Vect ds = velocity * dt;
    position += ds;

    velocity.setX(0.0);
    velocity.setY(0.0);
}
