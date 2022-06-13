#pragma once

#include "Character.h"
#include "../../Managers/EventManager.h"

using Managers::EventManager;
using Key = EventManager::Key;

namespace Entities {
    namespace Characters {
        class Player : public Character
        {
        private:
            bool canJump, stunned;
            float stunnedTime;

            Key moveRightKey, moveLeftKey, jumpKey;

        public:
            Player(const Vect pos = Vect(), Level *l = NULL, bool p2 = false);
            virtual ~Player();

            virtual void run(float dt);

            void setJump(const bool j);
            void setStunned(const bool s);
        };
    }
}