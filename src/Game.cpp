#include "Game.h"
#include <iostream>

Game::Game() :
level1()
{
    graphicsManager = GraphicsManager::getInstance();
    run();
}

Game::~Game()
{
    delete graphicsManager;
}

void Game::run()
{
    float dt;
    while(graphicsManager->isWindowOpen())
    {
        dt = graphicsManager->resetClock();
        graphicsManager->processEvents();

        level1.run(dt);

        graphicsManager->clearWindow();
        level1.draw();

        graphicsManager->draw();
    }
}
