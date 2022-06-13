#include "Bush.h"

#define DAMAGE 1

using namespace Entities::Obstacles;

Bush::Bush(const Vect pos) :
Obstacle(pos)
{
    setTexture("bush");
    setSize(Vect(57, 32));
}

Bush::~Bush() {}

const int Bush::getDamage() const {
    return DAMAGE;
}
