#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "../Ent.h"

namespace Entities {
    class Entity : public Ent {
    protected:
        sf::Vector2f position;
        sf::RectangleShape sprite;

    public:
        sf::Vector2f velocity;
        Entity();

        Entity(int x, int y, sf::Vector2f v = sf::Vector2f(0, 0));

        virtual ~Entity();

        virtual void run(float dt) = 0;

        virtual void draw();
    };
}
