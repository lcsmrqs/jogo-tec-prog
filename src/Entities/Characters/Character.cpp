#include <iostream>
#include "Character.h"
#include "../../Managers/GraphicsManager.h"

using Managers::GraphicsManager;
using namespace Entities::Characters;

Character::Character(const Vect pos, Level *l) :
Entity(pos, Vect(), l),
healthPoints(0)
{ }

Character::~Character() {}

int Character::getHealthPoints() const
{
    return healthPoints;
}

void Character::setHealthPoints(const int hp)
{
    healthPoints = hp;
}

void Character::run(float dt)
{
    velocity.setY(velocity.getY() + (981.0f * dt));
}

void Character::operator--() {
    healthPoints--;
}

