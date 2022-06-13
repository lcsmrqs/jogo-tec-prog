#pragma once

#include "Entity.h"

namespace Entities {
    class Floor : public Entity
    {
    public:
        Floor(const Vect pos = Vect(), const Vect size = Vect(), const int l = 1);
        ~Floor();

        void run(float dt);
    };
}
