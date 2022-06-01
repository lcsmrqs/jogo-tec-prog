#include "Character.h"
#include "../../Managers/GraphicsManager.h"

using Managers::GraphicsManager;
using namespace Entities::Characters;

Character::Character() : Entity() { }

Character::Character(Vect _size, Vect pos, Vect vel) : Entity(_size, pos, vel) {}

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

void Character::collide(Entity *e, Vect direction, float push)
{
    Entity::collide(e, direction, push);
    onCollision(direction);
}

void Character::onCollision(Vect direction)
{
    if(direction.getY() != 0.0f)
        velocity.setY(0.0f);
}


