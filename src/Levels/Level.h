#pragma once

#include "../Ent.h"
#include "../Lists/EntitiesList.h"
#include "../Managers/CollisionManager.h"
#include "../States/State.h"
#include "../Managers/EventListener.h"
#include "Checkpoint.h"

namespace Entities {
    namespace Characters {
        namespace Enemies {
            class Enemy;
        }
    }
}

using Entities::Characters::Enemies::Enemy;
using Levels::Checkpoint;
using Lists::EntitiesList;
using Managers::CollisionManager;
using Managers::EventListener;

namespace Levels {
    class Level : public Ent, public EventListener
    {
    protected:
        sf::Sprite background;
        EntitiesList entities;

        Floor *floor;
        Checkpoint *checkpoint;
        const float levelWidth;

        CollisionManager collisionManager;

        int nPlayers;
        std::list<Player*> players;

        std::list<Projectile*> toAddProj, toRemoveProj;
        std::list<Enemy*> toRemoveEnemies;
        std::list<Player*> toRemovePlayers;

        States::State *state;

        void updateView(const float dt);
        void drawBackground();

    public:
        Level(const int nPlayers = 1, const float w = 2500.0f);
        virtual ~Level();

        virtual void init() = 0;
        virtual void generateLevel() = 0;
        virtual void reset() = 0;
        virtual void finish() = 0;

        void run(float dt);
        void draw();
        void manageCollisions();

        virtual void onKeyPressed(Managers::Key k);
        virtual void onKeyReleased(Managers::Key k);

        void setState(States::State *s);
        void pause();

        void addObstacle(Obstacle *po);

        void addProjectile(Projectile *pp);
        void removeProjectile(Projectile *pp);
        void requestAddProj(Projectile *pp);
        void requestRemoveProj(Projectile *pp);

        void addEnemy(Enemy *pe);
        void removeEnemy(Enemy *pe);
        void requestRemoveEnemy(Enemy *pe);

        void addPlayer(Player *pp);
        void removePlayer(Player *pp);
        void requestRemovePlayer(Player *pp);

        // TODO: void cleanEntities();
    };
}
