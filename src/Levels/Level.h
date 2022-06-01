#pragma once

#include "../Ent.h"
#include "../Lists/EntitiesList.h"
#include "../Managers/CollisionManager.h"

using Lists::EntitiesList;
using Managers::CollisionManager;

namespace Levels {
    class Level : public Ent
    {
    protected:
        EntitiesList entities;
        CollisionManager collisionManager;

    public:
        Level();
        ~Level();

        void run(float dt);
        void draw();
        void manageCollisions();

    };
}
