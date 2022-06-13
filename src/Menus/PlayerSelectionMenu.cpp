#include "PlayerSelectionMenu.h"
#include "../States/PlayingState.h"
#include "../Levels/Forest.h"
#include "../Levels/Cave.h"

using namespace Menus;

using States::PlayingState;
using Levels::Forest;
using Levels::Cave;

PlayerSelectionMenu::PlayerSelectionMenu(const int l) :
Menu(),
level(l)
{
    options.push_back(new Button(Vect(0, 115), "1 player", true));
    options.push_back(new Button(Vect(0, 175), "2 player"));
    options.push_back(new Button(Vect(0, 235), "Back"));
}

PlayerSelectionMenu::~PlayerSelectionMenu() {}

void PlayerSelectionMenu::reset()
{
    std::vector<Button*>::iterator itr;
    for(itr = options.begin(); itr != options.end(); itr++)
        (*itr)->setActive(false);

    selectedOption = 0;
    options[selectedOption]->setActive(true);
}

void PlayerSelectionMenu::onKeyPressed(Key k)
{
    {
        Menu::onKeyPressed(k);

        if (k == Key::Enter)
            switch (selectedOption) {
                case 0:
                    play(1);
                    break;
                case 1:
                    play(2);
                    break;
                case 2:
                    back();
                    break;
            }
    }
}

void PlayerSelectionMenu::play(const int nPLayers) {
    switch(level)
    {
        case 1:
            {
                PlayingState *nextState = new PlayingState(new Forest(nPLayers), state->getContext());
                state->requestStackPop();
                state->requestStackPush(nextState);
            }
            break;
        case 2:
            {
                PlayingState *nextState = new PlayingState(new Cave(nPLayers), state->getContext());
                state->requestStackPop();
                state->requestStackPush(nextState);
            }
            break;
    }
}

void PlayerSelectionMenu::back()
{
    state->requestStackPop();
    state->requestResetTop();
}
