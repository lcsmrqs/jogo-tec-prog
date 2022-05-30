#include "Ground.h"

using namespace Entities::Obstacles;

Ground::Ground() :
Obstacle()
{
    id = 0;
    sprite.setSize(sf::Vector2f(600.0f, 32.0f));
    sprite.setOrigin(300.0f, 16.0f);
    sprite.setFillColor(sf::Color::Cyan);
    position.setX(400.0f);
    position.setY(300.0f);
}

Ground::~Ground() {}
