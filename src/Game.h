#pragma once

#include "Managers/GraphicsManager.h"
#include "Levels/Level.h"

using Managers::GraphicsManager;
using Levels::Level;

class Game
{
private:
    GraphicsManager *graphicsManager;
    Level level1;

public:
    Game();
    ~Game();
    void run();
};
