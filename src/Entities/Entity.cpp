#include "Entity.h"
#include "../Managers/GraphicsManager.h"
#include "../Levels/Level.h"

using namespace Entities;

using Managers::GraphicsManager;
using Levels::Level;

Entity::Entity(const Vect pos, const Vect vel, Level *l) :
Ent(),
size(),
position(pos),
velocity(vel),
hitBox(),
sprite(),
level(l)
{
    hitBox.setFillColor(sf::Color::Transparent);
/*
    hitBox.setOutlineColor(sf::Color::Red);
    hitBox.setOutlineThickness(2);
*/
}

Entity::~Entity()
{
    level = NULL;
}

void Entities::Entity::setTexture(const string s, const bool repeat)
{
    sf::Texture* texture = GraphicsManager::getInstance()->getTexture(s);
    if (texture)
    {
        if(repeat)
        {
            texture->setRepeated(true);
            sprite.setOrigin(size.getX() / 2, size.getY() / 2);
            sprite.setTextureRect(sf::IntRect(0, 0, size.getX(), size.getY()));
        }
        else
            sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);

        sprite.setTexture(*texture);
    }
}

void Entities::Entity::updateHitBox()
{
    hitBox.setSize(sf::Vector2f(size.getX(), size.getY()));
    hitBox.setOrigin(sf::Vector2f(size.getX() / 2, size.getY() / 2));
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

Vect Entities::Entity::getVelocity() const
{
    return velocity;
}

void Entities::Entity::setVelocity(const Vect v)
{
    velocity = v;
}

Vect Entity::getSize() const
{
    float x = hitBox.getSize().x;
    float y = hitBox.getSize().y;

    return Vect(x, y);
}

void Entities::Entity::setSize(const Vect s)
{
    size = s;
    updateHitBox();
}

Level* Entity::getLevel()
{
	return level;
}

void Entity::setLevel(Level *l)
{
	level = l;
}
