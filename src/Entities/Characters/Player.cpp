#include "Player.h"
#include "../../Managers/GraphicsManager.h"
#include <cmath>
#include "../../Levels/Level.h"

#define SPEED 150.0f

using Managers::GraphicsManager;
using Levels::Level;

using namespace Entities::Characters;

Player::Player(const Vect pos, Level *l, bool p2) :
Character(pos, l),
canJump(false),
stunned(false),
stunnedTime(0.0f),
moveLeftKey(Key::Left),
moveRightKey(Key::Right),
jumpKey(Key::Up)
{
    setHealthPoints(4);

    if(p2)
    {
        setTexture("rabico");
        setSize(Vect(64, 67));
        moveLeftKey = Key::A;
        moveRightKey = Key::D;
        jumpKey = Key::W;
    }
    else
    {
        setTexture("saci");
        setSize(Vect(32, 52));
    }
}

Player::~Player() {}

void Player::run(float dt)
{
    if(healthPoints <= 0)
    {
        level->requestRemovePlayer(this);
        return;
    }

    Character::run(dt);

    if(!stunned)
    {
        EventManager *em = EventManager::getInstance();

        if (em->isKeyPressed(moveRightKey) && velocity.getX() < SPEED / 2)
            velocity.setX(velocity.getX() + SPEED);

        if (em->isKeyPressed(moveLeftKey)  && velocity.getX() > -SPEED / 2)
            velocity.setX(velocity.getX() - SPEED);

        if (em->isKeyPressed(jumpKey) && canJump) {
            canJump = false;
            velocity.setY(-sqrtf(2 * 981.0f * 116.0f));
        }
    }
    else
    {
        stunnedTime += dt;
        if(stunnedTime > 0.75f)
            stunned = false;
    }

    Vect ds = velocity * dt;
    position += ds;
}

void Player::setJump(const bool j)
{
    canJump = j;
}

void Player::setStunned(const bool s)
{
    stunned = s;
    if(stunned)
        stunnedTime = 0;
}
