#include <iostream>
#include "Entity.h"
#include "../Managers/GraphicsManager.h"

using namespace Entities;
using Managers::GraphicsManager;

Entity::Entity() :
Ent(),
size(16.0f, 16.0f),
position(0.0f, 0.0f),
velocity(0.0f, 0.0f),
hitBox(sf::Vector2f(size.getX(), size.getY())),
sprite()
{
    init();
}

Entity::Entity(Vect _size, Vect pos, Vect vel) :
Ent(),
size(_size),
position(pos),
velocity(vel),
hitBox(sf::Vector2f(size.getX(), size.getY())),
sprite()
{
    init();
}

Entity::~Entity() {}

void Entity::init()
{
    hitBox.setFillColor(sf::Color::Transparent);
    hitBox.setOutlineColor(sf::Color::Red);
    hitBox.setOutlineThickness(1.0f);
    hitBox.setOrigin(size.getX() / 2, size.getY() / 2);
    texture = NULL;
}

void Entity::draw()
{
    GraphicsManager *graphics = GraphicsManager::getInstance();

    sf::Transform transform;
    transform.translate(sf::Vector2f(position.getX(), position.getY()));

    sf::RenderStates states(transform);

    graphics->getWindow()->draw(hitBox, states);
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
    float x = hitBox.getSize().x;
    float y = hitBox.getSize().y;

    return Vect(x, y);
}

void Entity::collide(Entity *e, Vect direction, float push)
{
    e->setPosition(e->getPosition() - (direction * push));
}


