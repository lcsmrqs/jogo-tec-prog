#pragma once

#include "Projectile.h"

namespace Entities {
    namespace Projectiles {
        class Fireball : public Projectile
        {
        public:
            Fireball(const Vect pos = Vect(), const Vect dir = Vect(), Level *l = NULL);
            ~Fireball();
        };
    }
}
