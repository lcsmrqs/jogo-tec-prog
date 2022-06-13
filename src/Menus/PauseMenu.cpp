#include "PauseMenu.h"

using namespace Menus;

PauseMenu::PauseMenu() :
Menu()
{
    options.push_back(new Button(Vect(0, 110), "Resume"));
    options.push_back(new Button(Vect(0, 170), "Restart"));
    options.push_back(new Button(Vect(0, 230), "Exit"));
}

PauseMenu::~PauseMenu() {}

void PauseMenu::reset()
{

}

void PauseMenu::onKeyPressed(Key k)
{
    Menu::onKeyPressed(k);

    if (k == Key::Enter)
        switch (selectedOption) {
            case 0:
                resume();
                break;
            case 1:
                restart();
                break;
            case 2:
                exit();
                break;
        }
}

void PauseMenu::resume()
{
    state->requestStackPop();
}

void PauseMenu::restart()
{
    state->requestStackPop();
    state->requestResetTop();
}

void PauseMenu::exit()
{
    state->requestStackPop();
    state->requestStackPop();
}
