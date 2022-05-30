#pragma once

#include "../Ent.h"
#include "../Math/Vect.h"
#include <SFML/Graphics/RectangleShape.hpp>

using Math::Vect;

namespace Entities {
    class Entity : public Ent
    {
    protected:
        Vect position;
        Vect velocity;
        sf::RectangleShape sprite;

    public:
        Entity();
        Entity(Vect pos, Vect vel);
        virtual ~Entity();

        virtual void run(float dt) = 0;
        virtual void draw();

        virtual void collide(Entity *e, Vect direction) = 0;

        Vect getPosition() const;
        void setPosition(const Vect p);

        Vect getSize();
    };
}
