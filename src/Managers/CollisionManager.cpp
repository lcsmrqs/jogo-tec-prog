#include "CollisionManager.h"
#include <cmath>

#include "../Entities/Projectiles/Projectile.h"
#include "../Entities/Characters/Player.h"
#include "../Entities/Characters/Enemies/Enemy.h"
#include "../Entities/Floor.h"
#include "../Entities/Obstacles/Obstacle.h"
#include "../Entities/Obstacles/Bush.h"
#include "../Entities/Obstacles/Stalagmite.h"
#include "../Levels/Level.h"
#include "../Levels/Checkpoint.h"

using namespace Managers;

using Entities::Obstacles::Bush;
using Entities::Obstacles::Stalagmite;

CollisionManager::CollisionManager(Level *l) :
players(),
enemies(),
obstacles(),
projectiles(),
level(l),
floor(),
checkpoint()
{}

CollisionManager::~CollisionManager()
{
    players.clear();
    enemies.clear();
    obstacles.clear();
}

void CollisionManager::setFloor(Floor *f) { floor = f; }

void Managers::CollisionManager::setLevel(Level *l) { level = l; }

void Managers::CollisionManager::setCheckpoint(Checkpoint *c) { checkpoint = c; }

void CollisionManager::addPlayer(Player *pp) { players.push_back(pp); }

void CollisionManager::removePlayer(Player *pp) { players.remove(pp); }

void CollisionManager::addEnemy(Enemy *pe) { enemies.push_back(pe); }

void CollisionManager::removeEnemy(Enemy *pe)
{
    std::vector<Enemy*>::iterator itr = enemies.begin();
    bool found = false;

    while(itr != enemies.end())
    {
        if(*itr == pe)
        {
            found = true;
            break;
        }

        itr++;
    }

    if(found)
        enemies.erase(itr);
}

void CollisionManager::addObstacle(Obstacle *po) { obstacles.push_back(po); }

void CollisionManager::addProjectile(Projectile *pp) { projectiles.push_back(pp); }

void CollisionManager::removeProjectile(Projectile *pp) { projectiles.remove(pp); }

bool CollisionManager::checkCollision(Entity *a, Entity *b, Vect& dir)
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
            dir.setX(0.0f);
            dir.setY(0.0f);

            if(intersect.getX() > intersect.getY())
            {
                if (delta.getX() > 0)
                    dir.setX(-1.0f * intersect.getX());
                else
                    dir.setX(intersect.getX());
            }
            else
            {
                if (delta.getY() > 0)
                    dir.setY(-1.0f * intersect.getY());
                else
                    dir.setY(intersect.getY());
            }
            return true;
        }
    }
    return false;
}

bool CollisionManager::checkCollision(Entity *a, Checkpoint *c)
{
    if(a && c)
    {
        Vect intersect, delta;

        delta.setX(a->getPosition().getX() - c->getPosition().getX());
        delta.setY(a->getPosition().getY() - c->getPosition().getY());

        intersect.setX(fabsf(delta.getX()) - (a->getSize().getX() / 2 + c->getSize().getX() / 2));
        intersect.setY(fabsf(delta.getY()) - (a->getSize().getY() / 2 + c->getSize().getY() / 2));

        if(intersect.getX() < 0.0f && intersect.getY() < 0.0f)
            return true;
    }
    return false;
}

void CollisionManager::manageCharactersFloorCollisions()
{
    std::list<Player*>::iterator playerItr;

    Vect collisionDir;

    for(playerItr = players.begin(); playerItr != players.end(); playerItr++)
        if(checkCollision(*playerItr, floor, collisionDir))
        {
            (*playerItr)->setPosition((*playerItr)->getPosition() + (collisionDir * 1.1));

            if(collisionDir.getY() < 0)
            {
                (*playerItr)->setVelocity(Vect((*playerItr)->getVelocity().getX() * 0.25f, 0.0f));
                (*playerItr)->setJump(true);
            }
        }

    std::vector<Enemy*>::iterator enemyItr;

    for(enemyItr = enemies.begin(); enemyItr != enemies.end(); enemyItr++)
        if(checkCollision(*enemyItr, floor, collisionDir))
        {
            (*enemyItr)->setPosition((*enemyItr)->getPosition() + (collisionDir));

            if(collisionDir.getY() < 0)
                (*enemyItr)->setVelocity(Vect((*enemyItr)->getVelocity().getX(), 0.0f));
        }
}

void Managers::CollisionManager::manageCharactersObstacleCollisions()
{
    std::list<Player*>::iterator playerItr;
    std::list<Obstacle*>::iterator obstacleItr;

    Vect collisionDir;

    for(playerItr = players.begin(); playerItr != players.end(); playerItr++)
        for(obstacleItr = obstacles.begin(); obstacleItr != obstacles.end(); obstacleItr++)
            if(checkCollision(*playerItr, *obstacleItr, collisionDir))
            {
                (*playerItr)->setPosition((*playerItr)->getPosition() + (collisionDir));

                if(collisionDir.getY() < 0)
                {
                    (*playerItr)->setVelocity(Vect((*playerItr)->getVelocity().getX() * 0.25f, 0.0f));
                    (*playerItr)->setJump(true);
                }
                else if(collisionDir.getY() > 0)
                    (*playerItr)->setVelocity(Vect((*playerItr)->getVelocity().getX(), 0.0f));
                else
                {
                    (*playerItr)->setVelocity(Vect(0, ((*playerItr)->getVelocity().getY() < 0.0f) ? (*playerItr)->getVelocity().getY() * 0.75 : (*playerItr)->getVelocity().getY()));
                }

                Bush *b = dynamic_cast<Bush*>(*obstacleItr);
                Stalagmite *s = dynamic_cast<Stalagmite*>(*obstacleItr);

                if(b || s)
                {
                    Vect diff = (*playerItr)->getPosition() - (*obstacleItr)->getPosition();
                    diff.setY(0.0);
                    diff = diff.normalize();

                    (*playerItr)->setVelocity(Vect( diff.getX() * 96, -sqrtf(2 * 981.0f * 32.0f))); // knockback
                    (*playerItr)->setPosition(Vect((*playerItr)->getPosition().getX(), (*playerItr)->getPosition().getY() - 8));
                    (*playerItr)->setStunned(true);
                    (*playerItr)->setJump(false);

                    int damage = 0;

                    if(b)
                        damage = b->getDamage();
                    else
                        damage = s->getDamage();

                    (*playerItr)->setHealthPoints((*playerItr)->getHealthPoints() - damage);
                }
            }

    std::vector<Enemy*>::iterator enemyItr;

    for(enemyItr = enemies.begin(); enemyItr != enemies.end(); enemyItr++)
        for(obstacleItr = obstacles.begin(); obstacleItr != obstacles.end(); obstacleItr++)
            if(checkCollision(*enemyItr, *obstacleItr, collisionDir))
            {
                (*enemyItr)->setPosition((*enemyItr)->getPosition() + (collisionDir));

                if(collisionDir.getY() < 0)
                    (*enemyItr)->setVelocity(Vect((*enemyItr)->getVelocity().getX() * 0.25f, 0.0f));
            }
}

void Managers::CollisionManager::managePlayersCheckpointCollision()
{
    std::list<Player*>::iterator playerItr;

    for(playerItr = players.begin(); playerItr != players.end(); playerItr++)
        if (checkCollision(*playerItr, checkpoint))
            level->finish();
}

void CollisionManager::managePlayerEnemyCollisions()
{
    std::list<Player*>::iterator playerItr;
    std::vector<Enemy*>::iterator enemyItr;

    Vect collisionDir;

    for(playerItr = players.begin(); playerItr != players.end(); playerItr++)
        for(enemyItr = enemies.begin(); enemyItr != enemies.end(); enemyItr++)
            if(checkCollision(*playerItr, *enemyItr, collisionDir))
            {
                (*enemyItr)->setPosition((*enemyItr)->getPosition() - (collisionDir));
                if(collisionDir.getY() < 0) // player "pisando" no enemy
                {
                    (*enemyItr)->operator--();

                    (*playerItr)->setVelocity(Vect((*playerItr)->getVelocity().getX(), 0.0f));
                    (*playerItr)->setJump(true);
                }
                else if(collisionDir.getY() > 0) // enemy pisando no player
                {
                    (*playerItr)->setHealthPoints((*playerItr)->getHealthPoints() - (*enemyItr)->getDamage());

                    Vect diff = (*playerItr)->getPosition() - (*enemyItr)->getPosition();
                    diff.setY(0.0);
                    diff = diff.normalize();

                    (*playerItr)->setVelocity(Vect( diff.getX() * 128, -sqrtf(2 * 981.0f * 24.0f))); // knockback
                    (*playerItr)->setPosition(Vect((*playerItr)->getPosition().getX(), (*playerItr)->getPosition().getY() - 8));
                }
                else // colisao na horizontal
                {
                    (*playerItr)->setHealthPoints((*playerItr)->getHealthPoints() - (*enemyItr)->getDamage());

                    (*playerItr)->setVelocity(Vect((collisionDir.normalize().getX() * 128), -sqrtf(2 * 981.0f * 48.0f))); // knockback
                    (*playerItr)->setPosition(Vect((*playerItr)->getPosition().getX() + (collisionDir.normalize().getX() * 8), (*playerItr)->getPosition().getY() - 8));
                    (*playerItr)->setStunned(true);
                    (*playerItr)->setJump(false);
                }
            }

    for(int i = 0; i < enemies.size() - 1; i++)
        for(int j = i+1; j < enemies.size(); j++)
            if(checkCollision(enemies[i], enemies[j], collisionDir))
            {
                enemies[i]->setPosition(enemies[i]->getPosition() + (collisionDir));
                enemies[j]->setPosition(enemies[j]->getPosition() - (collisionDir));
            }
}

void CollisionManager::manageProjectilesPlayerCollisions()
{
    std::list<Projectile*>::iterator projectileItr;
    std::list<Player*>::iterator playerItr;

    Vect collisionDir;

    for(playerItr = players.begin(); playerItr != players.end(); playerItr++)
        for(projectileItr = projectiles.begin(); projectileItr != projectiles.end(); projectileItr++)
            if(checkCollision(*playerItr, *projectileItr, collisionDir))
            {
                (*projectileItr)->setPosition((*projectileItr)->getPosition() + (collisionDir * -1.0f));


                (*playerItr)->operator--();

                (*playerItr)->setVelocity(Vect((collisionDir.normalize().getX() * 128), -sqrtf(2 * 981.0f * 48.0f))); // knockback
                (*playerItr)->setPosition(Vect((*playerItr)->getPosition().getX() + (collisionDir.normalize().getX() * 8), (*playerItr)->getPosition().getY() - 8));
                (*playerItr)->setStunned(true);
                (*playerItr)->setJump(false);

                if(level)
                    level->requestRemoveProj(*projectileItr);
            }

}

void CollisionManager::manageCollisions()
{
    managePlayersCheckpointCollision();

    manageCharactersFloorCollisions();

    manageCharactersObstacleCollisions();

    managePlayerEnemyCollisions();
    manageProjectilesPlayerCollisions();
}

void Managers::CollisionManager::clearAll()
{
    players.clear();
    enemies.clear();
    obstacles.clear();
    projectiles.clear();
}
