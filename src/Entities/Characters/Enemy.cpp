#include "Enemy.h"
#include <cmath>

#define SPEED 90.0f

using namespace Entities::Characters;

Enemy::Enemy(Player *_pPlayer) :
Character(),
pPlayer(_pPlayer)
{
    init();
}

Enemy::Enemy(Vect _size, Vect pos, Vect vel, Player *_pPlayer) :
Character(_size, pos, vel),
pPlayer(_pPlayer)
{
    init();
}

void Enemy::init()
{
    texture = new sf::Texture;
    if(texture->loadFromFile("../../assets/characters/enemies/curupira.png"))
    {
        sprite.setTexture(*texture, true);
        sprite.setOrigin(16.0f, 23.5f);
    }
}

Enemy::~Enemy()
{
    delete texture;
}

void Enemy::run(float dt)
{
    Character::run(dt);

    if(pPlayer)
    {
        Vect diff = pPlayer->getPosition() - position;
        float magnitude = diff.getMagnitude();

        if(magnitude < 300.0f)
        {
            if (magnitude >= (fmaxf(pPlayer->getSize().getX(), pPlayer->getSize().getY()) + fmaxf(getSize().getX(), getSize().getY())) / 2) {
                if (magnitude > 1.0f)
                    diff = diff.normalize();

                velocity.setX(fmin(fmax(-98.0f, velocity.getX() + SPEED * diff.getX()), 98.0f));
            }
        }

        velocity.setX(velocity.getX() * 0.9f);
    }

    Vect ds = velocity * dt;
    position += ds;
}
