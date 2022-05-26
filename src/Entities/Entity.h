#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "../Ent.h"
#include "../Math/Vect.h"

namespace Entities {
    class Entity : public Ent {
    protected:
        Math::Vect position;
        Math::Vect velocity;
        sf::RectangleShape sprite;

    public:
        Entity();

        Entity(Math::Vect pos, Math::Vect vel);

        virtual ~Entity();

        virtual void run(float dt) = 0;

        virtual void draw();
    };
}
