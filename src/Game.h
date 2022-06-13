#pragma once

#include "Managers/GraphicsManager.h"
#include "States/StateStack.h"

using Managers::GraphicsManager;
using States::StateStack;

class Game
{
private:
    GraphicsManager *graphicsManager;
    StateStack *stateStack;

public:
    Game();
    ~Game();
    void run();
};
