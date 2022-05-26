#include <iostream>
#include "Entity.h"
#include "../Managers/GraphicsManager.h"

using namespace Entities;
using Managers::GraphicsManager;

Entity::Entity() :
        Ent(), sprite(sf::Vector2f(16, 16)), position(0, 0), velocity(0, 0)
{
    sprite.setFillColor(sf::Color::Red);
}

Entity::Entity(Math::Vect pos, Math::Vect vel) :
        Ent(), sprite(sf::Vector2f(16, 16)), position(pos), velocity(vel)
{
    sprite.setFillColor(sf::Color::Red);
    sprite.setPosition(position.getX(), position.getY());
}

Entity::~Entity() {}

void Entity::draw() {
    GraphicsManager *graphics = GraphicsManager::getInstance();

    sf::Transform transform;
    transform.translate(sf::Vector2f(position.getX(), position.getY()));

    sf::RenderStates states(transform);

    graphics->getWindow()->draw(sprite, states);
}
