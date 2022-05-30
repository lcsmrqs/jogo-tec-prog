#include "Game.h"
#include <iostream>

Game::Game() {
    graphicsManager = GraphicsManager::getInstance();
    collisionManager = new CollisionManager();

    saci = new Saci(Vect(250.0f, 200.0f), Vect(0.0f, 0.0f));

    enemy = new Enemy(saci);
    enemy->setPosition(Vect(50.0f, 50.0f));

    ground = new Ground;

    run();
}

Game::~Game() {
    delete saci;
    delete enemy;

    delete collisionManager;
    delete graphicsManager;

}

void Game::run() {
    float dt;
    while(graphicsManager->isWindowOpen())
    {
        dt = graphicsManager->resetClock();
        graphicsManager->processEvents();

        // run entities
        saci->run(dt);
        enemy->run(dt);
        ground->run(dt);

        // check collisions
        collisionManager->checkCollision(saci, enemy);

        if(collisionManager->checkCollision(saci, ground))
            collisionManager->checkCollision(saci, enemy);

        if(collisionManager->checkCollision(enemy, ground))
            collisionManager->checkCollision(saci, enemy);

        // draw entities
        graphicsManager->clearWindow();
        enemy->draw();
        saci->draw();
        ground->draw();

        graphicsManager->draw();
    }
}
