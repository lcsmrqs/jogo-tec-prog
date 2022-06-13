#include "Curupira.h"

#define DAMAGE 1

using namespace Entities::Characters::Enemies;

Curupira::Curupira(const Vect pos, Level *l) :
Enemy(pos, l)
{
    setTexture("curupira");
    setSize(Vect(32, 47));
    setHealthPoints(1);
    maxSpeed = 75.0f;
}

Curupira::~Curupira() {}

const int Curupira::getDamage() const {
    return DAMAGE;
}
