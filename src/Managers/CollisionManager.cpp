#include "CollisionManager.h"
#include <cmath>

using namespace Managers;

CollisionManager::CollisionManager() :
players(),
enemies(),
obstacles()
{}

CollisionManager::~CollisionManager()
{
    players.clear();
    enemies.clear();
    obstacles.clear();
}

void CollisionManager::addPlayer(Player *pp) { players.push_back(pp); }

void CollisionManager::addEnemy(Enemy *pe) { enemies.push_back(pe); }

void CollisionManager::addObstacle(Obstacle *po) { obstacles.push_back(po); }

bool CollisionManager::checkCollision(Entity *a, Entity *b, float push)
{
    if(a && b)
    {
        Vect intersect, delta;

        delta.setX(a->getPosition().getX() - b->getPosition().getX());
        delta.setY(a->getPosition().getY() - b->getPosition().getY());

        intersect.setX(fabsf(delta.getX()) - (a->getSize().getX() / 2 + b->getSize().getX() / 2));
        intersect.setY(fabsf(delta.getY()) - (a->getSize().getY() / 2 + b->getSize().getY() / 2));

        if(intersect.getX() < 0.0f && intersect.getY() < 0.0f)
        {
            Vect direction(0.0f, 0.0f);

            if(intersect.getX() > intersect.getY())
                if(delta.getX() > 0)
                    direction.setX(-1.0f * intersect.getX());
                else
                    direction.setX(intersect.getX());
            else
                if(delta.getY() > 0)
                    direction.setY(-1.0f * intersect.getY());
                else
                    direction.setY(intersect.getY());

            push = fminf(fmaxf(push, 0.0f), 1.0f);

            a->collide(b, direction, push);
            b->collide(a, direction * -1.0f, (1.0f - push));

            return true;
        }
    }

    return false;
}

void CollisionManager::managePlayerEnemyCollisions(float push)
{
    std::list<Player*>::iterator playerItr;
    std::vector<Enemy*>::iterator enemyItr;

    for(playerItr = players.begin(); playerItr != players.end(); playerItr++)
        for(enemyItr = enemies.begin(); enemyItr != enemies.end(); enemyItr++)
            checkCollision(*playerItr, *enemyItr, push);
}

void CollisionManager::managePlayerObstacleCollisions()
{
    std::list<Player*>::iterator playerItr;
    std::list<Obstacle*>::iterator obstacleItr;

    for(playerItr = players.begin(); playerItr != players.end(); playerItr++)
        for(obstacleItr = obstacles.begin(); obstacleItr != obstacles.end(); obstacleItr++)
            if(checkCollision(*playerItr, *obstacleItr, 0.0f))
                managePlayerEnemyCollisions();
}

void CollisionManager::manageObstacleEnemyCollisions()
{
    std::list<Obstacle*>::iterator obstacleItr;
    std::vector<Enemy*>::iterator enemyItr;

    for(obstacleItr = obstacles.begin(); obstacleItr != obstacles.end(); obstacleItr++)
        for(enemyItr = enemies.begin(); enemyItr != enemies.end(); enemyItr++)
            if(checkCollision(*obstacleItr, *enemyItr))
                managePlayerEnemyCollisions(0.0f);
}

void CollisionManager::manageCollisions()
{
    managePlayerEnemyCollisions(0.5f);
    managePlayerObstacleCollisions();
    manageObstacleEnemyCollisions();
    // TODO: manage projectile collision
}
