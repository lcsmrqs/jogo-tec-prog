#include "Stalagmite.h"

#define DAMAGE 2

using namespace Entities::Obstacles;

Stalagmite::Stalagmite(const Vect pos) :
Obstacle(pos)
{
    setTexture("stalagmite");
    setSize(Vect(50, 47));
}

Stalagmite::~Stalagmite() {}

const int Stalagmite::getDamage() const {
    return DAMAGE;
}
