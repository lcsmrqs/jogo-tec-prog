#pragma once

#include "Menu.h"

namespace Menus {
    class MainMenu : public Menu
    {
    public:
        MainMenu();
        ~MainMenu();

        void reset();
        void onKeyPressed(Key k);

        void playLevel(const int n);
        void load();
        void leaderboard();
        void quit();
    };
}
