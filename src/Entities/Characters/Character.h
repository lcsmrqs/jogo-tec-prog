#pragma once

#include "../Entity.h"

namespace Entities {
    namespace Characters {
        class Character : public Entity
        {
        protected:
            int healthPoints;

        public:
            Character(const Vect pos = Vect(), Level *l = NULL);
            virtual ~Character();

            int getHealthPoints() const;
            void setHealthPoints(const int hp);

            void operator--();

            virtual void run(float dt);
        };
    }
}
