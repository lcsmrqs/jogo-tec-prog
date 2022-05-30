#include <iostream>
#include "Entity.h"
#include "../Managers/GraphicsManager.h"

using namespace Entities;
using Managers::GraphicsManager;

Entity::Entity() :
Ent(),
sprite(sf::Vector2f(16, 16)),
position(0.0f, 0.0f),
velocity(0.0f, 0.0f)
{
    sprite.setFillColor(sf::Color::White);
    sprite.setOrigin(8.0f, 8.0f);
}

Entity::Entity(Vect pos, Vect vel) :
Ent(),
sprite(sf::Vector2f(16, 16)),
position(pos),
velocity(vel)
{
    sprite.setFillColor(sf::Color::White);
    sprite.setOrigin(8.0f, 8.0f);
}

Entity::~Entity() {}

void Entity::draw()
{
    GraphicsManager *graphics = GraphicsManager::getInstance();

    sf::Transform transform;
    transform.translate(sf::Vector2f(position.getX(), position.getY()));

    sf::RenderStates states(transform);

    graphics->getWindow()->draw(sprite, states);
}

Vect Entity::getPosition() const
{
    return position;
}

void Entity::setPosition(const Vect p)
{
    position = p;
}

Vect Entity::getSize()
{
    float x = sprite.getSize().x;
    float y = sprite.getSize().y;

    return Vect(x, y);
}
