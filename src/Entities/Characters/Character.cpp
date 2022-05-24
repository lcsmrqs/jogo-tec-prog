#include "Character.h"
#include "../../Managers/GraphicsManager.h"

using Managers::GraphicsManager;
using namespace Entities::Characters;

Character::Character() : Entity() {}

Character::Character(int x, int y) : Entity(x, y) {}

Character::Character(int x, int y, sf::Vector2f v) : Entity(x, y, v) {}

Character::~Character() {}

void Character::run(float dt) {
    if (position.x < 0 && velocity.x < 0) // check ranges
    {
        position.x = 0;
        velocity *= -1.f;
    } else if (position.x > (WINDOW_WIDTH - sprite.getSize().x) && velocity.x > 0) {
        position.x = WINDOW_WIDTH - sprite.getSize().x;
        velocity *= -1.f;
    }

    sf::Vector2f ds = velocity * dt; // displacement
    position += ds;
}
