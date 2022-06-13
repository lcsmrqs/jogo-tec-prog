#pragma once

#include "Menu.h"

namespace Menus {
    class PauseMenu : public Menu
    {
    public:
        PauseMenu();
        ~PauseMenu();

        void onKeyPressed(Key k);
        void reset();

        void resume();
        void restart();
        void exit();

    };
}
