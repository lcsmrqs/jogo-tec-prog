#pragma once

#include "Obstacle.h"

namespace Entities {
    namespace Obstacles {
        class Stalagmite : public Obstacle
        {
        public:
            Stalagmite(const Vect pos = Vect());
            ~Stalagmite();

            const int getDamage() const;
        };
    }
}
