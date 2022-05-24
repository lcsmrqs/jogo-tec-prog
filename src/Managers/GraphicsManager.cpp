#include <SFML/Window/Event.hpp>
#include "GraphicsManager.h"

using namespace Managers;

GraphicsManager *GraphicsManager::instance = NULL;

GraphicsManager::GraphicsManager() :
        window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game"),
        clock()
{
}

GraphicsManager *GraphicsManager::getInstance() {
    if(!instance) instance = new GraphicsManager();
    return instance;
}

bool GraphicsManager::isWindowOpen() const {
    return window.isOpen();
}

void GraphicsManager::clearWindow() {
    window.clear();
}

void GraphicsManager::draw() {
    window.display();
}

void GraphicsManager::processEvents() {
    sf::Event event;
    while(window.pollEvent(event))
        if(event.type == sf::Event::Closed)
            window.close();
}

sf::RenderWindow *GraphicsManager::getWindow() {
    return &window;
}

void GraphicsManager::resetClock() {
    clock.restart();
}

float GraphicsManager::getDt() {
    return clock.getElapsedTime().asSeconds();
}
