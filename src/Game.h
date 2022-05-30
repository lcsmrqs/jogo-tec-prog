#pragma once

#include "Managers/GraphicsManager.h"
#include "Managers/CollisionManager.h"
#include "Entities/Characters/Saci.h"
#include "Entities/Characters/Enemy.h"
#include "Entities/Obstacles/Ground.h"

using Managers::GraphicsManager;
using Managers::CollisionManager;
using Entities::Characters::Saci;
using Entities::Characters::Enemy;
using Entities::Obstacles::Ground;

class Game
{
private:
    GraphicsManager *graphicsManager;
    CollisionManager *collisionManager;
    Saci *saci;
    Enemy *enemy;
    Ground *ground;

public:
    Game();
    ~Game();
    void run();
};
