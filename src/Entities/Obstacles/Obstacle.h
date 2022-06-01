#pragma once

#include "../Entity.h"

namespace Entities {
    namespace Obstacles {
        class Obstacle : public Entity
        {
        private:
            void init();
        public:
            Obstacle();
            Obstacle(Vect size, Vect pos, Vect vel = Vect(0.0f, 0.0f));
            virtual ~Obstacle();

            virtual void run(float dt);
        };
    }
}
