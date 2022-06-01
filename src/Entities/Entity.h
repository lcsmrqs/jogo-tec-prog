#pragma once

#include "../Ent.h"
#include "../Math/Vect.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using Math::Vect;

namespace Entities {
    class Entity : public Ent
    {
    protected:
        Vect position;
        Vect velocity;
        Vect size;
        sf::RectangleShape hitBox;
        sf::Sprite sprite;
        sf::Texture *texture;

        void init();

    public:
        Entity();
        Entity(Vect size, Vect pos, Vect vel = Vect(0.0f, 0.0f));
        virtual ~Entity();

        virtual void run(float dt) = 0;
        virtual void draw();

        virtual void collide(Entity *e, Vect direction, float push);

        Vect getPosition() const;
        void setPosition(const Vect p);

        Vect getSize();
    };
}
