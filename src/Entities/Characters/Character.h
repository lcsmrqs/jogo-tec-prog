#pragma once

#include "../Entity.h"

namespace Entities {
    namespace Characters {
        class Character : public Entity
        {
        protected:
            int health; // TODO: getters and setters

        public:
            Character();
            Character(Math::Vect pos, Math::Vect vel);
            ~Character();
            void run(float dt);
        };
    }
}
