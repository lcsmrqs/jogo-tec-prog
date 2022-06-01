#pragma once

#include "Character.h"

namespace Entities {
    namespace Characters {
        class Player : public Character
        {
        private:
            bool canJump;
            void init();

        public:
            Player();
            Player(Vect _size, Vect pos, Vect vel = Vect(0.0f, 0.0f));
            virtual ~Player();

            virtual void run(float dt);
            void onCollision(Vect direction);
        };
    }
}