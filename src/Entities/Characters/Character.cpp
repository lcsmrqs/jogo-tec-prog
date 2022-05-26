#include "Character.h"
#include "../../Managers/GraphicsManager.h"


using Managers::GraphicsManager;
using namespace Entities::Characters;

Character::Character() : Entity() {}

Character::Character(Math::Vect pos, Math::Vect vel) : Entity(pos, vel) {}

Character::~Character() {}

void Character::run(float dt) {
    if (position.getX() < 0 && velocity.getX() < 0) // check ranges
    {
        position.setX(0);
        velocity *= -1.f;
    } else if ((int) position.getX() > (WINDOW_WIDTH - sprite.getSize().x) && velocity.getX() > 0) {
        position.setX(WINDOW_WIDTH - sprite.getSize().x);
        velocity *= -1.f;
    }

    Math::Vect ds = velocity * dt; // displacement
    position += ds;
}
