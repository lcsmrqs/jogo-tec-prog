#include "CollisionManager.h"
#include <cmath>

using namespace Managers;

CollisionManager::CollisionManager() {}

CollisionManager::~CollisionManager() {}

bool CollisionManager::checkCollision(Entity *a, Entity *b)
{
    if(a && b)
    {
        Vect intersect, delta;

        delta.setX(a->getPosition().getX() - b->getPosition().getX());
        delta.setY(a->getPosition().getY() - b->getPosition().getY());

        intersect.setX(fabs(delta.getX()) - (a->getSize().getX() / 2 + b->getSize().getX() / 2));
        intersect.setY(fabs(delta.getY()) - (a->getSize().getY() / 2 + b->getSize().getY() / 2));

        if(intersect.getX() < 0.0f && intersect.getY() < 0.0f)
        {
            Vect direction(0.0f, 0.0f);

            if(intersect.getX() > intersect.getY())
                if(delta.getX() > 0)
                    direction.setX(- intersect.getX());
                else
                    direction.setX(intersect.getX());
            else
                if(delta.getY() > 0)
                    direction.setY(- intersect.getY());
                else
                    direction.setY(intersect.getY());

            a->collide(b, direction);
            b->collide(a, direction * (-1.0f));

            return true;
        }
    }

    return false;
}
