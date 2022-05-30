#include "Player.h"
#include <iostream>

using namespace Entities::Characters;

Player::Player() :
Character()
{
    id = 1;
    sprite.setFillColor(sf::Color::Blue);
}

Player::Player(Vect pos, Vect vel) :
Character(pos, vel)
{
    id = 1;
    sprite.setFillColor(sf::Color::Blue);
}

Player::~Player()
{
}

void Player::run(float dt)
{
    Character::run(dt);
}

void Player::collide(Entity *e, Vect direction)
{
    if(e->getId() == 2)
    {
        Vect ds = direction * -0.5f;
        e->setPosition(e->getPosition() + ds);
    }
}
