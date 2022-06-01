#pragma once

#include "../Entities/Entity.h"
#include <list>
#include <vector>
#include "../Entities/Characters/Player.h"
#include "../Entities/Characters/Enemy.h"
#include "../Entities/Obstacles/Obstacle.h"

using Entities::Entity;
using Entities::Characters::Enemy;
using Entities::Characters::Player;
using Entities::Obstacles::Obstacle;

namespace Managers {
    class CollisionManager
    {
    private:
        std::list<Player*> players;
        std::vector<Enemy*> enemies;
        std::list<Obstacle*> obstacles;
        // TODO: projectile list

    public:
        CollisionManager();
        ~CollisionManager();

        void addPlayer(Player *pp);
        void addObstacle(Obstacle *po);
        void addEnemy(Enemy *pe);

        bool checkCollision(Entity *a, Entity *b, float push = 1.0f);
        void managePlayerEnemyCollisions(float push = 1.0f);
        void managePlayerObstacleCollisions();
        void manageObstacleEnemyCollisions();
        void manageCollisions();

    };
}
