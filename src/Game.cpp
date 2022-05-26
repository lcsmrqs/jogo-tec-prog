#include "Game.h"
#include <iostream>

Game::Game() {
    graphics = GraphicsManager::getInstance();
    playerChar = new Character(Math::Vect(0.f, 0.f), Math::Vect(750.f, 0.f));
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
