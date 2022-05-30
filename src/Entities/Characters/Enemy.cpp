#include "Enemy.h"

#define SPEED 90.0f

using namespace Entities::Characters;

Enemy::Enemy(Player *_pPlayer) :
Character(),
pPlayer(_pPlayer)
{
    id = 2;
    sprite.setSize(sf::Vector2f(32.0f, 32.0f));
    sprite.setOrigin(16.0f, 16.f);
    sprite.setFillColor(sf::Color::Yellow);
}

Enemy::~Enemy() {}

void Enemy::run(float dt)
{
    if(pPlayer)
    {
        velocity *= 0.0f;
        Vect diff = pPlayer->getPosition() - position;

        if(diff.getMagnitude() > pPlayer->getSize().getMagnitude())
        {
            if(diff.getMagnitude() > 1.0f)
                diff = diff.normalize();

            velocity = diff * SPEED;
        }

        Vect ds = velocity * dt;
        position += ds;
    }
}

void Enemy::collide(Entity *e, Vect direction)
{
    if(e->getId() == 1)
    {
        Vect ds = direction * -0.5f;
        e->setPosition(e->getPosition() + ds);
    }
}
