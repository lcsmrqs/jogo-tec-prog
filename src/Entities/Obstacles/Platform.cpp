#include "Platform.h"

using namespace Entities::Obstacles;

Platform::Platform(const Vect pos, const Vect size, const int type) :
Obstacle(pos, size)
{
    if(type == 1)
        setTexture("floor-grass", true);
    else if(type == 2)
        setTexture("floor-mud", true);
    setSize(size);
}

Platform::~Platform() {}
