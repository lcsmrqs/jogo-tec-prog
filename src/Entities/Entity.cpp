//#include <iostream>
#include "Entity.h"
#include "../Managers/GraphicsManager.h"

using namespace Entities;
using Managers::GraphicsManager;

Entity::Entity() :
        Ent(), sprite(sf::Vector2f(16, 16)), position(0, 0), velocity(0, 0)
{
    sprite.setFillColor(sf::Color::Red);
}

Entity::Entity(int x, int y, sf::Vector2f v) :
        Ent(), sprite(sf::Vector2f(16, 16)), position(x, y), velocity(v)
{
    sprite.setFillColor(sf::Color::Red);
    sprite.setPosition(x, y);
}

Entity::~Entity() {}

void Entity::draw() {
//    std::cout << position.x << " " << position.y << std::endl;
    GraphicsManager *graphics = GraphicsManager::getInstance();

    sf::Transform transform;
    transform.translate(position);
    sf::RenderStates states(transform);

    graphics->getWindow()->draw(sprite, states);
}
