#include "GraphicsManager.h"

#include <iostream>

using namespace Managers;

GraphicsManager *GraphicsManager::instance = NULL;

GraphicsManager::GraphicsManager() :
window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game"),
clock(),
textures(),
view(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT))
{
    eventManager = EventManager::getInstance();
    window.setFramerateLimit(30);
    window.setKeyRepeatEnabled(false);
    window.setView(view);

    font = new sf::Font;
    if(!font->loadFromFile("../../assets/PressStart2P-Regular.ttf"))
        exit(1);
}

GraphicsManager::~GraphicsManager()
{
	map<string, sf::Texture*>::iterator aux, itr = textures.begin();
	while(itr != textures.end())
	{
		aux = itr;
		itr++;
		delete aux->second;
		textures.erase(aux);
	}

	delete font;
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
            eventManager->onKeyPressed((EventManager::Key) event.key.code);
        }
        else if (event.type == sf::Event::KeyReleased && eventManager)
        {
            eventManager->onKeyReleased((EventManager::Key) event.key.code);
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

void GraphicsManager::closeWindow()
{
    window.close();
}

sf::Font* GraphicsManager::getFont()
{
	return font;
}

bool GraphicsManager::loadTexture(const string tName)
{
	sf::Texture *texture = new sf::Texture;
	if(texture->loadFromFile("../../assets/" + tName + ".png"))
	{
		textures[tName] = texture;
		return true;
	}
	return false;
}

sf::Texture* GraphicsManager::getTexture(const string t)
{
	if(!textures[t])
		loadTexture(t);

	return textures[t];
}

    void GraphicsManager::updateView(const Vect v)
{
    view.move(v.getX(), v.getY());
//    view.set
    window.setView(view);
}

void GraphicsManager::resetView()
{
    view = window.getDefaultView();
    window.setView(window.getDefaultView());
}

Vect GraphicsManager::getViewCenter()
{
    sf::Vector2f c = view.getCenter();
    return Vect(c.x, c.y);
}
