#include "MulaSemCabeca.h"
#include "../../../Managers/GraphicsManager.h"
#include "../../../Levels/Level.h"
#include "../../Projectiles/Fireball.h"
#include <cmath>

#define SPEED 95.0f
#define FIREBALL_COOLDOWN 7.5f
#define DAMAGE 1

using namespace Entities::Characters::Enemies;

using Managers::GraphicsManager;
using Levels::Level;
using Entities::Projectiles::Fireball;

MulaSemCabeca::MulaSemCabeca(const Vect pos, Level *l) :
Enemy(pos, l),
fireballCooldown(FIREBALL_COOLDOWN)
{
    setTexture("mula-sem-cabeca");
    setSize(Vect(47, 65));
    setHealthPoints(1);
    maxSpeed = 100.0f;
}

MulaSemCabeca::~MulaSemCabeca() {}

void MulaSemCabeca::run(float dt)
{
    if(healthPoints == 0)
    {
        level->requestRemoveEnemy(this);
        return;
    }

    Character::run(dt);

    velocity.setX(velocity.getX() * 0.9f);

    fireballCooldown += dt;

    if(!players.empty())
    {
        Player *pPlayer;
        Vect diff(0.0, 0.0);
        float playerDistance = 0.0, lowest = 99999.9;

        std::list<Player*>::iterator playerItr = players.begin();

        for( ; playerItr != players.end(); playerItr++)
        {
            Player *pp = *playerItr;
            diff = pp->getPosition() - position;
            playerDistance = diff.getMagnitude();

            if(playerDistance < lowest)
            {
                pPlayer = pp;
                lowest = playerDistance;
            }
        }

        diff = pPlayer->getPosition() - position;
        playerDistance = diff.getMagnitude();

        if(playerDistance < 175.0f) // distancia para seguir o player
        {
            if (playerDistance > 1.0f)
                diff = diff.normalize();

            velocity.setX(fmin(fmax(- maxSpeed, velocity.getX() + SPEED * diff.getX()), maxSpeed));
        }
        else if(playerDistance < 275.0f && fabs(diff.getY()) < 32.0f)
		{
            diff = diff.normalize();

            if(fireballCooldown >= FIREBALL_COOLDOWN)
                throwFireball(Vect(diff.getX(), 0.0f));
		}
    }

    Vect ds = velocity * dt;
    position += ds;
}

void MulaSemCabeca::throwFireball(Vect direction)
{
    Fireball *f = new Fireball(position, direction, level);

    fireballCooldown = 0;

    level->requestAddProj(static_cast<Projectile*>(f));
}

const int MulaSemCabeca::getDamage() const {
    return DAMAGE;
}
