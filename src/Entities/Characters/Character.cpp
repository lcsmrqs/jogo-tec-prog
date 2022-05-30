#include "Character.h"
#include "../../Managers/GraphicsManager.h"

using Managers::GraphicsManager;
using namespace Entities::Characters;

Character::Character() : Entity() {}

Character::Character(Vect pos, Vect vel) : Entity(pos, vel) {}

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
    if (position.getX() < 0 && velocity.getX() < 0) // check ranges
    {
        position.setX(0);
        velocity *= -1.f;
    } else if (position.getX() > (WINDOW_WIDTH - sprite.getSize().x) && velocity.getX() > 0) {
        position.setX(WINDOW_WIDTH - sprite.getSize().x);
        velocity *= -1.f;
    }

    Vect ds = velocity * dt; // displacement
    position += ds;
}
