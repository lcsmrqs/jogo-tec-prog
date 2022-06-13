#pragma once

#include "Obstacle.h"

namespace Entities {
    namespace Obstacles {
        class Bush : public Obstacle
        {
        public:
            Bush(const Vect pos = Vect());
            ~Bush();

            const int getDamage() const;
        };
    }
}
