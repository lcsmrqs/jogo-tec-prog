#pragma once

#include "../Entity.h"

namespace Entities {
    namespace Obstacles {
        class Obstacle : public Entity
        {
        public:
            Obstacle();
            virtual ~Obstacle();

            virtual void run(float dt);
            virtual void collide(Entity *e, Vect direction);
        };
    }
}
