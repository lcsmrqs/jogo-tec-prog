#pragma once

#include "Managers/GraphicsManager.h"
#include "Entities/Characters/Character.h"

using Managers::GraphicsManager;
using Entities::Characters::Character;

class Game
{
private:
    GraphicsManager *graphics;
    Character *playerChar;

public:
    Game();
    ~Game();
    void run();
};
