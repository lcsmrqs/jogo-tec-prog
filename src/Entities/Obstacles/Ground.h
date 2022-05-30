#pragma once

#include "Obstacle.h"

namespace Entities {
    namespace Obstacles {
        class Ground : public Obstacle
        {
        public:
            Ground();
            ~Ground();
        };
    }
}