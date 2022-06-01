#include "Obstacle.h"

using namespace Entities::Obstacles;

Obstacle::Obstacle() :
Entity()
{
    init();
}

Obstacle::Obstacle(Vect _size, Vect pos, Vect vel) :
Entity(_size, pos, vel)
{
    init();
}

void Obstacle::init()
{
    texture = new sf::Texture;
    if(texture->loadFromFile("../../assets/obstacles/platform-mud.png"))
    {
        sprite.setTexture(*texture, true);
        sprite.setOrigin(16, 16);
    }
}

Obstacle::~Obstacle()
{
    delete texture;
}

void Obstacle::run(float dt) {}
