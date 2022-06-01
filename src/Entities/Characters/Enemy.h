#pragma once

#include "Character.h"
#include "Player.h"

namespace Entities {
    namespace Characters {
        class Enemy : public Character
        {
        protected:
            Player *pPlayer;
            void init();

        public:
            Enemy(Player *_pPlayer = NULL);
            Enemy(Vect size, Vect pos, Vect vel = Vect(0.0f, 0.0f), Player *_pPlayer = NULL);
            ~Enemy();

            virtual void run(float dt);
        };
    }
}
