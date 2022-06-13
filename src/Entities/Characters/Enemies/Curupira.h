#pragma once

#include "Enemy.h"

namespace Entities {
    namespace Characters {
        namespace Enemies {
            class Curupira : public Enemy
            {
            public:
                Curupira(const Vect pos = Vect(), Level *l = NULL);
                ~Curupira();

                const int getDamage() const;
            };
        }
    }
}
