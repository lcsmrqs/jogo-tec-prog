#include "Enemy.h"
#include <cmath>
#include "../../../Managers/GraphicsManager.h"
#include "../../../Levels/Level.h"

#define SPEED 100.0f

using namespace Entities::Characters::Enemies;

using Managers::GraphicsManager;
using Levels::Level;

Enemy::Enemy(const Vect pos, Level *l) :
Character(pos, l),
players(),
maxSpeed(0.0)
{
}

Enemy::~Enemy()
{
    players.clear();
}

void Enemy::run(float dt)
{
    if(healthPoints <= 0)
    {
        level->requestRemoveEnemy(this);
        return;
    }

    Character::run(dt);

    velocity.setX(velocity.getX() * 0.9f);

    if(!players.empty())
    {
        Player *pPlayer;
        Vect diff(0.0, 0.0);
        float playerDistance = 0.0, lowest = 99999.9;

        std::list<Player*>::iterator playerItr = players.begin();

        for( ; playerItr != players.end(); playerItr++)
        {
            Player *pp = *playerItr;
            diff = pp->getPosition() - position;
            playerDistance = diff.getMagnitude();

            if(playerDistance < lowest)
            {
                pPlayer = pp;
                lowest = playerDistance;
            }
        }

        diff = pPlayer->getPosition() - position;
        playerDistance = diff.getMagnitude();

        if(playerDistance < 225.0f)
        {
            if (playerDistance > 1.0f)
                diff = diff.normalize();

            velocity.setX(fmin(fmax(-maxSpeed, velocity.getX() + SPEED * diff.getX()), maxSpeed));
        }
    }



    Vect ds = velocity * dt;
    position += ds;
}

void Enemy::addPlayer(Player *pp)
{
    if(pp)
        players.push_back(pp);
}

void Enemy::removePlayer(Player *pp)
{
    if(pp)
        players.remove(pp);
}
