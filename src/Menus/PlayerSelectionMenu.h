#pragma once

#include "Menu.h"

namespace States {
    class PlayingState;
}

using States::PlayingState;

namespace Menus {
    class PlayerSelectionMenu : public Menu
    {
    private:
        int level;

    public:
        PlayerSelectionMenu(const int level);
        ~PlayerSelectionMenu();

        virtual void reset();

        virtual void onKeyPressed(Key k);

        void play(const int nPLayers);
        void back();

    };
}
