#pragma once

#include "State.h"
#include "../Menus/Menu.h"

using Menus::Menu;

namespace States {
    class MenuState : public State
    {
    private:
        Menu *menu;

    public:
        MenuState(Menu *m = NULL, StateStack *c = NULL);
        ~MenuState();

        void setMenu(Menu *m);

        void run(float dt);
        void draw();
        void reset();

        void onKeyPressed(Managers::Key k);
        void onKeyReleased(Managers::Key k);
    };
}
