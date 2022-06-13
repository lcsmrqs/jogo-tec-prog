#pragma once

#include "Obstacle.h"

namespace Entities {
    namespace Obstacles {
        class Platform : public Obstacle
        {
        public:
            Platform(const Vect pos = Vect(), const Vect size = Vect(), const int type = 1);
            ~Platform();
        };
    }
}
