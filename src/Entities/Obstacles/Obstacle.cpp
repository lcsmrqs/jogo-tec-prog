#include "Obstacle.h"

#include "../../Managers/GraphicsManager.h"

using Managers::GraphicsManager;

using namespace Entities::Obstacles;

Obstacle::Obstacle(const Vect pos, Vect size) :
Entity(pos)
{
    setSize(size);
}

Obstacle::~Obstacle() {}

void Obstacle::run(float dt) {}
