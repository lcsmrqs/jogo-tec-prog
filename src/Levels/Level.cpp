#include "Level.h"

using namespace Levels;

Level::Level() :
Ent(),
entities(),
collisionManager()
{
    Player *player = new Player(Vect(16.0f, 52.0f), Vect(400.0f, 300.0f), Vect(0.0f, 0.0f));
    Enemy *enemy = new Enemy(Vect(16.0f, 47.0f), Vect(48.0f, 200.0f), Vect(0.0f, 0.0f), player);

    Obstacle *platform;

    entities.addEntity(static_cast<Entity*>(player));
    collisionManager.addPlayer(player);

    entities.addEntity(static_cast<Entity*>(enemy));
    collisionManager.addEnemy(enemy);

    for(int i = 0; i < 25; i++)
    {
        platform = new Obstacle(Vect(32.0f, 32.0f), Vect(i * 32.0f + 2 * i + 17, 433.0f));

        entities.addEntity(static_cast<Entity*>(platform));
        collisionManager.addObstacle(platform);
    }



}

Level::~Level()
{
    for(int i = 0; i < entities.size(); i++)
        delete entities[i];

    entities.clear();
}

void Level::run(float dt)
{
    for(int i = 0; i < entities.size(); i++)
        entities[i]->run(dt);

    manageCollisions();
}

void Level::draw()
{
    for(int i = 0; i < entities.size(); i++)
        entities[i]->draw();
}

void Level::manageCollisions()
{
    collisionManager.manageCollisions();
}
