#include "Projectile.h"
#include "../../Managers/GraphicsManager.h"
#include "../../Levels/Level.h"

using Managers::GraphicsManager;
using Levels::Level;

using namespace Entities::Projectiles;

Projectile::Projectile(const Vect pos, const Vect vel, Level *l) :
Entity(pos, vel, l),
lifetime(0.0f)
{
}

Projectile::~Projectile()
{
}

void Projectile::run(float dt)
{
    position += velocity * dt;
    lifetime += dt;

    if(lifetime >= 1.5f)
        level->requestRemoveProj(this);
}
