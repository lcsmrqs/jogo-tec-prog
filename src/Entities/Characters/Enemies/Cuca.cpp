#include "Cuca.h"

#define DAMAGE 2

using namespace Entities::Characters::Enemies;

Cuca::Cuca(const Vect pos, Level *l) :
Enemy(pos, l)
{
    setTexture("cuca");
    setSize(Vect(46, 65));
    setHealthPoints(3);
    maxSpeed = 150.0f;
}

Cuca::~Cuca() {}

const int Cuca::getDamage() const {
    return DAMAGE;
}
