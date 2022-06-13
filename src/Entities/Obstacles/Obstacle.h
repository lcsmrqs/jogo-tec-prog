#pragma once

#include "../Entity.h"

namespace Entities {
    namespace Obstacles {
        class Obstacle : public Entity
        {
        public:
            Obstacle(const Vect pos = Vect(), Vect size = Vect());
            virtual ~Obstacle();

            void run(float dt);

        };
    }
}
