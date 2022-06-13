#include "Fireball.h"

#define FIREBALL_SPEED 325.0f

using namespace Entities::Projectiles;

Fireball::Fireball(const Vect pos, const Vect dir, Level *l) :
Projectile(pos, dir * FIREBALL_SPEED, l)
{
    setTexture("fireball");
    setSize(Vect(28, 16));
}

Fireball::~Fireball() {}
