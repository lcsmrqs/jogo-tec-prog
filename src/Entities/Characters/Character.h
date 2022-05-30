#pragma once

#include "../Entity.h"

namespace Entities {
    namespace Characters {
        class Character : public Entity
        {
        protected:
            int healthPoints;

        public:
            Character();
            Character(Vect pos, Vect vel);
            virtual ~Character();

            virtual void run(float dt);
            void collide(Entity *e, Vect direction) = 0;

            int getHealthPoints() const;
            void setHealthPoints(const int hp);
        };
    }
}
