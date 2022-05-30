#pragma once

#include "Character.h"

namespace Entities {
    namespace Characters {
        class Player : public Character
        {
        public:
            Player();
            Player(Vect pos, Vect vel);
            virtual ~Player();

            virtual void run(float dt);
            void collide(Entity *e, Vect direction);

        };
    }
}