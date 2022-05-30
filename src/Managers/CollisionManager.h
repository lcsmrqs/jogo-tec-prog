#pragma once

#include "../Entities/Entity.h"

using Entities::Entity;

namespace Managers {
    class CollisionManager
    {
    public:
        CollisionManager();
        ~CollisionManager();

        bool checkCollision(Entity *a, Entity *b);
    };
}
