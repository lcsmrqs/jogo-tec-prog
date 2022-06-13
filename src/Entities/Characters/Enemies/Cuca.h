#pragma once

#include "Enemy.h"

namespace Entities {
    namespace Characters {
        namespace Enemies {
            class Cuca : public Enemy
            {
            public:
                Cuca(const Vect pos = Vect(), Level *l = NULL);
                ~Cuca();

                const int getDamage() const override;
            };
        }
    }
}
