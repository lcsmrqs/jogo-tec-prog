#include "MainMenu.h"
#include "../Game.h"
#include "../States/PlayingState.h"
#include "../Levels/Level.h"
#include "../States/MenuState.h"
#include "../Menus/PlayerSelectionMenu.h"

using namespace Menus;

using States::PlayingState;
using Levels::Level;
using States::MenuState;
using Menus::PlayerSelectionMenu;

MainMenu::MainMenu() :
Menu()
{
    options.push_back(new Button(Vect(0, 50), "Level 1", true));
    options.push_back(new Button(Vect(0, 110), "Level 2"));
    options.push_back(new Button(Vect(0, 170), "Load Game"));
    options.push_back(new Button(Vect(0, 230), "Leaderboard"));
    options.push_back(new Button(Vect(0, 290), "Exit"));
}

MainMenu::~MainMenu() {}

void MainMenu::reset()
{
    std::vector<Button*>::iterator itr;
    for(itr = options.begin(); itr != options.end(); itr++)
        (*itr)->setActive(false);

    selectedOption = 0;
    options[selectedOption]->setActive(true);
}

void MainMenu::onKeyPressed(Key k)
{
    Menu::onKeyPressed(k);

    if (k == Key::Enter)
        switch (selectedOption) {
            case 0:
                playLevel(1);
                break;
            case 1:
                playLevel(2);
                break;
            case 2:
                load();
                break;
            case 3:
                leaderboard();
                break;
            case 4:
                quit();
                break;
        }
}

void MainMenu::playLevel(const int n)
{
    PlayerSelectionMenu *selectionMenu = new PlayerSelectionMenu(n);

    state->requestStackPush(new MenuState(selectionMenu, state->getContext()));
    state->requestResetTop();
}

void MainMenu::load() {}

void MainMenu::leaderboard()
{
    // push RankingMenu
    // pop
}

void MainMenu::quit()
{
	state->requestStackPop();
}
