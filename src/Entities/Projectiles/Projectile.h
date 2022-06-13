#pragma once

#include "../Entity.h"

namespace Entities {
    namespace Projectiles {
        class Projectile : public Entity
        {
        protected:
            float lifetime;

        public:
            Projectile(const Vect pos = Vect(), const Vect vel = Vect(), Level *l = NULL);
            virtual ~Projectile();

            void run(float dt);
        };
    }
}