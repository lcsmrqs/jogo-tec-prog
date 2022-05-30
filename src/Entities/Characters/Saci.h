#pragma once

#include "Player.h"

namespace Entities {
    namespace Characters {
        class Saci : public Player
        {
        public:
            Saci();
            Saci(Vect pos, Vect vel);
            ~Saci();

            void run(float dt);
        };
    }
}