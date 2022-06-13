#include "Button.h"
#include "../Managers/GraphicsManager.h"
#include <cmath>

using namespace Menus;
using Managers::GraphicsManager;

Button::Button(Vect pos, const string s, const bool a) :
Ent(),
box(),
text(),
active(a),
timer(0.0f)
{
    box.setSize(sf::Vector2f(200, 40));
    box.setOrigin(box.getSize() / 2.0f);
    box.setFillColor(sf::Color(100, 100, 100));
    box.setOutlineColor(sf::Color(175, 175, 175));
    box.setOutlineThickness(2);
    box.setPosition(WINDOW_WIDTH / 2, pos.getY());


    sf::Font *font = GraphicsManager::getInstance()->getFont();
    text.setFont(*font);
    text.setString(s);
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::White);
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(box.getPosition());
}

Button::~Button() {}

void Button::setActive(const bool a)
{
    active = a;
    timer = 0.0f;
}

void Button::setText(const string s) { text.setString(s); }

void Button::run(float dt)
{
    timer = fmodf(timer + dt, 1.0f);
    if(active)
    {
        box.setOutlineColor(sf::Color(255, 255, 255, 255 - (timer * 2550) / 10));
    }
    else
        box.setOutlineColor(sf::Color(125, 125, 125));
}

void Button::draw() {
    GraphicsManager *graphics = GraphicsManager::getInstance();

    graphics->getWindow()->draw(box);
    graphics->getWindow()->draw(text);
}
