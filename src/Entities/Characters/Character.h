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
            Character(Vect size, Vect pos, Vect vel = Vect(0.0f, 0.0f));
            virtual ~Character();

            int getHealthPoints() const;
            void setHealthPoints(const int hp);

            virtual void run(float dt);
            virtual void collide(Entity *e, Vect direction, float push);

            virtual void onCollision(Vect direction);
        };
    }
}
