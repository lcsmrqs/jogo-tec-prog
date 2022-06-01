#include "GraphicsManager.h"

#include <iostream>

using namespace Managers;

GraphicsManager *GraphicsManager::instance = NULL;

GraphicsManager::GraphicsManager() :
        window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game"),
        clock()
{
    eventManager = EventManager::getInstance();
    window.setFramerateLimit(30);
    window.setKeyRepeatEnabled(false);
}

GraphicsManager::~GraphicsManager()
{
    delete eventManager;
}

GraphicsManager *GraphicsManager::getInstance()
{
    if(!instance) instance = new GraphicsManager();
    return instance;
}

bool GraphicsManager::isWindowOpen() const
{
    return window.isOpen();
}

void GraphicsManager::clearWindow()
{
    window.clear();
}

void GraphicsManager::draw()
{
    window.display();
}

void GraphicsManager::processEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed && eventManager)
        {
            eventManager->keyPressed((EventManager::Key) event.key.code);
        }
        else if (event.type == sf::Event::KeyReleased && eventManager)
        {
            eventManager->keyReleased((EventManager::Key) event.key.code);
        }
    }
}

sf::RenderWindow* GraphicsManager::getWindow()
{
    return &window;
}

float GraphicsManager::resetClock()
{
    return clock.restart().asSeconds();
}
