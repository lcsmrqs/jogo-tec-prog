#pragma once

#include "../Ent.h"
#include "../Math/Vect.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using Math::Vect;
using std::string;

namespace Levels {
	class Level;
}

using Levels::Level;

namespace Entities {
    class Entity : public Ent
    {
    protected:
        Vect position;
        Vect velocity;
        Vect size;
        sf::RectangleShape hitBox;
        sf::Sprite sprite;

        Level *level;

        void setTexture(const string s, const bool repeat = false);
        void updateHitBox();

    public:
        Entity(const Vect pos = Vect(), const Vect vel = Vect(), Level *l = NULL);
        virtual ~Entity();

        virtual void run(float dt) = 0;
        virtual void draw();

        Vect getPosition() const;
        void setPosition(const Vect p);

        Vect getVelocity() const;
        void setVelocity(const Vect v);

        Vect getSize() const;
        void setSize(const Vect s);

        Levels::Level* getLevel();
        void setLevel(Levels::Level *l);
    };
}
