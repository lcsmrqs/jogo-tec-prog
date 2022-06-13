#pragma once

#include "../Entities/Entity.h"
#include <list>
#include <vector>

using Entities::Entity;

namespace Entities {
    class Floor;
    namespace Projectiles {
        class Projectile;
    }
    namespace Characters {
        class Player;
        namespace Enemies {
            class Enemy;
        }
    }
    namespace Obstacles {
        class Obstacle;
    }
}

namespace Levels {
    class Level;
    class Checkpoint;
}

using Entities::Characters::Player;
using Entities::Characters::Enemies::Enemy;
using Entities::Projectiles::Projectile;
using Entities::Obstacles::Obstacle;
using Entities::Floor;
using Levels::Checkpoint;


namespace Managers {
    class CollisionManager
    {
    private:
        Level *level;

        std::list<Player*> players;
        std::vector<Enemy*> enemies;
        std::list<Obstacle*> obstacles;
        std::list<Projectile*> projectiles;

        Floor *floor;
        Checkpoint *checkpoint;

        bool checkCollision(Entity *a, Entity *b, Vect& dir);
        bool checkCollision(Entity *a, Checkpoint *c);

        void manageCharactersFloorCollisions();
        void manageCharactersObstacleCollisions();
        void managePlayersCheckpointCollision();
        void managePlayerEnemyCollisions();
        void manageProjectilesPlayerCollisions();
        //void manageProjectilesObstaclesCollisions();

    public:
        CollisionManager(Level *l = NULL);
        ~CollisionManager();

        void setFloor(Floor *f);
        void setLevel(Level *l);
        void setCheckpoint(Checkpoint *c);

        void addPlayer(Player *pp);
        void removePlayer(Player *pp);

        void addObstacle(Obstacle *po);

        void addEnemy(Enemy *pe);
        void removeEnemy(Enemy *pe);

        void addProjectile(Projectile *pp);
        void removeProjectile(Projectile *pp);

        void manageCollisions();

        void clearAll();

    };
}
