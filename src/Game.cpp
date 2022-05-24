#include "Game.h"
#include <iostream>

Game::Game() {
    graphics = GraphicsManager::getInstance();
    playerChar = new Character(0, 0, sf::Vector2f(750.0f, 0.0f));
    run();
}

Game::~Game() {
    delete playerChar;
}

void Game::run() {
    while(graphics->isWindowOpen())
    {
        graphics->processEvents();
        graphics->clearWindow();

        playerChar->run(graphics->getDt());
        playerChar->draw();

        graphics->draw();
        graphics->resetClock();
    }
}
