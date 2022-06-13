#include "Game.h"
#include "States/State.h"
#include "States/PlayingState.h"
#include "States/MenuState.h"

#include "Menus/MainMenu.h"

using States::State;
using States::PlayingState;
using States::MenuState;
using Menus::MainMenu;

Game::Game()
{
    graphicsManager = GraphicsManager::getInstance();

    MenuState *initialState = new MenuState(new MainMenu);

    stateStack = new StateStack(initialState);

    run();
}

Game::~Game()
{
    delete stateStack;
    delete graphicsManager;
}

void Game::run()
{
    float dt;
    while(graphicsManager->isWindowOpen())
	{
        dt = graphicsManager->resetClock();
        graphicsManager->processEvents();

        stateStack->run(dt);

        if(stateStack->empty())
		{
			graphicsManager->closeWindow();
			break;
		}

        graphicsManager->clearWindow();
        stateStack->draw();

        graphicsManager->draw();
    }
}
