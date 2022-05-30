#include "Obstacle.h"

using namespace Entities::Obstacles;

Obstacle::Obstacle() : Entity() {}

Obstacle::~Obstacle() {}

void Obstacle::collide(Entities::Entity *e, Vect direction)
{
    if(e->getId() == 1 || e->getId() == 2)
    {
        e->setPosition(e->getPosition() - direction);
    }
}

void Obstacle::run(float dt) {}
