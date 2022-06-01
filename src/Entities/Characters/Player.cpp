#include "Player.h"
#include "../../Managers/EventManager.h"

#include <cmath>

#define SPEED 150.0f

using Managers::EventManager;
using Key = EventManager::Key;

using namespace Entities::Characters;

Player::Player() :
Character()
{
    init();
}

Player::Player(Vect _size, Vect pos, Vect vel) :
Character(_size, pos, vel)
{
    init();
}

void Player::init() {
    texture = new sf::Texture;
    if(texture->loadFromFile("../../assets/characters/players/saci.png"))
    {
        sprite.setTexture(*texture, true);
        sprite.setOrigin(20.0f, 26.0f);
    }
}

Player::~Player()
{
    delete texture;
}

void Player::run(float dt)
{
    Character::run(dt);

    EventManager *em = EventManager::getInstance();

    if(em->isKeyPressed(Key::Right))
        velocity.setX(velocity.getX() + SPEED);
    if(em->isKeyPressed(Key::Left))
        velocity.setX(velocity.getX() - SPEED);

    if(em->isKeyPressed(Key::Up) && canJump)
    {
        canJump = false;
        velocity.setY(-sqrtf( 2 * 981.0f * 96.0f ));
    }

    Vect ds = velocity * dt;
    position += ds;

    velocity.setX(0.0f);
}

void Player::onCollision(Vect direction) {
    Character::onCollision(direction);
    if(direction.getY() < 0.0f) canJump = true;
}
