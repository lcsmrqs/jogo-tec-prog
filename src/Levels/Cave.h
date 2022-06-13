#pragma once

#include "Level.h"

namespace Levels {
    class Cave : public Level
    {
    public:
        Cave(const int players = 1, const float w = 3500.0);
        ~Cave();

        void init();
        void generateLevel();
        void reset();
        void finish();

        virtual void onKeyPressed(Managers::Key k);
    };
}
