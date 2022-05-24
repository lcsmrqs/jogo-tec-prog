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
            Character(int x, int y);
            Character(int x, int y, sf::Vector2f v);
            ~Character();
            void run(float dt);
        };
    }
}
