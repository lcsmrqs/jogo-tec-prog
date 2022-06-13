#pragma once

#include "../Ent.h"
#include "../Math/Vect.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

using std::string;
using Math::Vect;

namespace Menus {
    class Button : public Ent
    {
    private:
        sf::RectangleShape box;
        sf::Text text;
        bool active;
        float timer;

    public:
        Button(Vect pos, const string s = "", const bool a = false);
        ~Button();

        void setActive(const bool a);
        void setText(const string s);

        void run(float dt);
        void draw();
    };
}
