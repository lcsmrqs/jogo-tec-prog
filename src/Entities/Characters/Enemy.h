#pragma once

#include "Character.h"
#include "Player.h"

namespace Entities {
    namespace Characters {
        class Enemy : public Character
        {
        protected:
            Player *pPlayer;

        public:
            Enemy(Player *_pPlayer = NULL);
            ~Enemy();

            virtual void run(float dt);
            void collide(Entity *e, Vect direction);
        };
    }
}
